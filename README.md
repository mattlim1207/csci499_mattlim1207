# csci499_mattlim1207

To run the project, first clone glog using the following command

	git clone git@github.com:google/glog.git

Then cd into the created glog directory, then run 

	cmake -H. -Bbuild -G "Unix Makefiles"
	cmake --build build
	cmake --build build --target install

Then, cd into the build directory, and run

	cmake ..

Run the created executable ./caw with any corresponding flags.