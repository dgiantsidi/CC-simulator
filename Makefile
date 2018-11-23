target:
	g++ Main.cpp cache.cpp processor.cpp MSI.cpp -o CC -std=c++11
	# g++ Main.cpp cache.cpp

clean:
	rm CC
