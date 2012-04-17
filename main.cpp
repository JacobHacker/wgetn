#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>

#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

using namespace std;

const string NUM_IDENTIFIER = "%04d";

bool wget(string url){
	int child = fork();
	
	if(child < 0){
		std::cout << "Failed to fork, exiting.\n";
		exit(1);
	}else if(child == 0){
		cout << "Downloading " << url << " ...\n";
		execl("/usr/bin/wget", "wget", "-q", url.c_str(), NULL);
	}
}



int main(int argc, char **argv){
	//for(int i=1; i<argc; i++){
	///	cout << argv[i] << endl;
	//}
	string url = argv[1];
	string numbers = argv[2];
	
	//split numbers
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	BOOST_FOREACH(string t, tokens){
		cout << t << "." << endl;
	}
	
	//first find the number identifier
	size_t location;
	location = url.find(NUM_IDENTIFIER);
	
	url.replace(location, NUM_IDENTIFIER.size(), numbers);
	cout << url << endl;
	
	
	return EXIT_SUCCESS;
}
