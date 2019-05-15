#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;
using namespace std;
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int main(){

	XMLDocument gomaaxml;
	XMLNode * sysnode = gomaaxml.NewElement("system");					// <systrm>
	gomaaxml.InsertFirstChild(sysnode);
	XMLElement * Intgr = gomaaxml.NewElement("Intger");					//		<intger>
	Intgr->SetText(10); //inner Html									//					10
	sysnode->InsertEndChild(Intgr);										//		</intger>
	XMLElement * Float = gomaaxml.NewElement("Float");					//		<float>
	XMLElement * Button = gomaaxml.NewElement("Button");				//				
	Button->SetAttribute("ID", "myButton");								//				<Button ID="myButton" class="AnyButton>
	Button->SetAttribute("class", "AnyButton");							//								 
	Button->SetText("Word");											//				word
	Float->InsertFirstChild(Button);									//				</Button>
	sysnode->InsertEndChild(Float);										//		</float>
	XMLError eResult = gomaaxml.SaveFile("SavedData.xml");				// </system>
	XMLCheckResult(eResult);
	
	XMLDocument DS;
	eResult = DS.LoadFile("DS.xml");
	XMLCheckResult(eResult);
	XMLNode * html = DS.FirstChild();
	if (html == nullptr) cout<<"what html? \n";
	XMLElement * user = html->FirstChildElement("user");
	if (user == nullptr) cout << "what user? \n";
	int Date;
	eResult = user->QueryIntText(&Date);
	XMLCheckResult(eResult);
	cout << " date    " << Date;

}