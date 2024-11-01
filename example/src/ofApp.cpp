#include "ofApp.h"

#include "absl/strings/str_join.h"
#include "absl/types/optional.h"
#include "absl/hash/hash.h"
#include "absl/container/flat_hash_map.h"
#include "absl/types/any.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();

	// test of absl str_join

	std::vector<std::string> v = {"foo", "bar", "baz"};
  	std::string s = absl::StrJoin(v, "-");

	ofLogNotice("ofApp") << "absl::StrJoin(v, \"-\") = " << s;

	// test of absl optional

	absl::optional<int> o1 = 42;
	absl::optional<int> o2 = absl::nullopt;
	
	ofLogNotice("ofApp") << "absl::optional: o1 = " << o1.value_or(0);
	ofLogNotice("ofApp") << "absl::optional: o2 = " << o2.value_or(0);
    
    // test of absl hash
    
    absl::Hash<std::string> hasher;
	std::string str = "hello";
	size_t hash = hasher(str);

	ofLogNotice("ofApp") << "absl::Hash<std::string>: hash = " << hash;

	// test of hash map of any type

	absl::flat_hash_map<std::string, absl::any> map;
	map["int"] = 42;
	map["string"] = std::string("hello");

	ofLogNotice("ofApp") << "absl::flat_hash_map<std::string, absl::any>: map[\"int\"] = " << absl::any_cast<int>(map["int"]);
	ofLogNotice("ofApp") << "absl::flat_hash_map<std::string, absl::any>: map[\"string\"] = " << absl::any_cast<std::string>(map["string"]);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
