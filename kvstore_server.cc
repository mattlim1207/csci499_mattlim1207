#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include <iostream>
#include <map>

#include "./proto/kvstore.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using kvstore::GetReply;
using kvstore::GetRequest;
using kvstore::PutReply;
using kvstore::PutRequest;
using kvstore::RemoveReply;
using kvstore::RemoveRequest;
using kvstore::KeyValueStore;
using std::map;

static map<std::string, std::string> storage;

static std::string getValue(const std::string key) {
  std::string values = "";
  for (auto it = storage.begin(); it != storage.end(); it++) {
    if (it->first.compare(key)) {
      values += it->second + " ";
    }
  }
  return values;
}

class KeyValueStoreServiceImpl final : public KeyValueStore::Service {
  Status put(ServerContext *context, const PutRequest *request,
             PutReply *response) override {
    storage.insert({request->key().c_str(), request->value().c_str()});
    return Status::OK;
  }

  Status get(
      ServerContext *context,
      ServerReaderWriter<GetReply, GetRequest>
          *stream) override {
   /* GetRequest request;
    while (stream->Read(&request)) {
      GetReply reply;
      reply.set_value(getValue(request.key().c_str()));
      stream->Write(reply);
    }*/
    return Status::OK;
  }

  Status remove(ServerContext *context,
                const RemoveRequest *request,
                RemoveReply *response) override {
    storage.erase(request->key());
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  KeyValueStoreServiceImpl service;

  grpc::ServerBuilder builder;

  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  // Register "service" as the instance through which we'll communicate with
  // clients. In this case, it corresponds to an *synchronous* service.
  builder.RegisterService(&service);

  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main() {
  RunServer();

  return 0;
}
