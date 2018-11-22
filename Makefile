target:
	g++ Main.cpp cache.cpp processor.cpp MSI.cpp -o CC
	# g++ Main.cpp cache.cpp

clean:
	rm CC
