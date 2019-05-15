#include"tinyxml2.h"
#include<algorithm>
#include<iostream>
#include <string>
#include <vector>
using namespace tinyxml2;
using namespace std;
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif
int users_count;
XMLDocument dataBase;

class user;
vector <user> users;
vector <int> free_ids;
class admin
{
	void createAccount(string name)
	{}
	void deleteAccount(int Id)
	{}
	void preview(int Id)
	{}
	
};
struct comments
{
	int id;
	string comment;
};

class post
{
private:
	
	vector <int> likes;
	vector <comments> comment;
	
public:
	string text;
	int pid;
	post(string text)
	{
		this->text = text;

	}
	void like_post(int f_id) {

		likes.push_back(f_id);
		if (likes.size() - 1 != 0){
			cout << "and other " <<likes.size() - 1;
		}
	}
	int total_likes() {
		return likes.size();
	}
	void commenting(int f_id, string f_comment) {
		comments temp;
		temp.id = f_id;
		temp.comment = f_comment;
		comment.push_back(temp);
	}
	void delete_like(int f_id) {
		std::vector<int>::iterator it;
		//int pos;
		// Element to be searched
		// std::find function call
		//it = std::find(likes.begin(), likes.end(), f_id); //5665
		/*if (it != likes.end())
		{
		pos=it - likes.begin() + 1 ;
		}*/
		likes.erase(it);
	}
	int comment_count(void)//count total number of comments
	{
		return comment.size();

	}
	void delete_comment(int f_id, string f_comment) {
		comments temp;
		temp.id = f_id;
		temp.comment = f_comment;
		vector<int>::iterator it;
		//it = std::find(likes.begin(), likes.end(), temp); //5665
		//comment.erase(remove(comment.begin(), comment.end(), it), comment.end());
	}
	/*string show_post() {

		return this->text;


	}*/
	void show_post(/*int user_id, int post_id*/); /*{

		cout<<this->text<<endl;
		cout<<"likes : "<<likes.size();
		cout<<"Comments : "<<endl;

		for(int i=0;i<comment.size();i++)
		{
			cout<<users[comment[i].id].getName()<<" : "<<comment[i].comment<<endl;
		}
	}*/
	
	/*
	string show_likes()
	{
	string c;
	for (int i = likes.size() - 1; i > -1; i--)
	   {
			int temp1=
			c += my_map[temp1]+'/n';// assume my map by ids
	   }
	}
	*/


/*
post(string text);// constructor
void like_post(int f_id);// add friend id to like list
void delete_like(int f_id);
int total_likes();//count total likes for a post
void commenting(int f_id, string f_comment);//add comment to post & who write it in comment vector
int comment_count(void);//count total number of comments
void delete_comment(int f_id,sting f_comment);
string show_post();// show post string & its likes & comments
string show_likes();//names of friends liking post
*/
	friend class user;

};

class user {
private:
	int id;
	string name;
	int age;//can be int but separate it in days/month/year
	vector<post> posts;
	vector<int>friends;
	vector<int>id_friend_request;
	vector<int>waiting_acceptance;
	//bool flag_user = false;
public:
	user(){};
	user(string name);
	user(int age, string name);//constructor 
	void accept_friend(int id);//see list of request & preview data & decide accept(make sure to delete it from request list) or no
	void add_friend(string name_to_add/*or use his name*/);//wait for acceptance & add it to waiting list
	void write_post(string post);
	void like_f_post(int f_id, int f_post_id);
	void write_comment(string f_comment, int f_id, int f_post_id);//comment for friend's post
	void preview_all_posts();
	void preview_profile();//preview user data/friends names/posts 
	void preview_friend(string f_name); //preview friend data + friend posts
	int get_id();
	void delete_friend(); // Must delete its comments and likes too
	void delete_post();
	void user::accept_friend();
	static int get_id(string find_name);
	string getName(){
		return name;
	}
 	void static delete_user(int user_to_del)
	{

		///loop on friends and delete his likes and comments
		for(int i=0;i<users[user_to_del].friends.size();i++)
		{

			auto it=std::find(users[users[user_to_del].friends[i]].friends.begin(),users[users[user_to_del].friends[i]].friends.end(),user_to_del);
			users[users[user_to_del].friends[i]].friends.erase(it);

			for(int j=0;j<users[users[user_to_del].friends[i]].posts.size();j++){

				/*	while(find(users[users[user_to_del].friends[i]].posts[j].comment.begin(),users[users[user_to_del].friends[i]].posts[j].comment.end(),user_to_del)!=users[users[user_to_del].friends[i]].posts[j].comment.end()){

				auto it1=std::find(users[users[user_to_del].friends[i]].posts[j].comment.begin(),users[users[user_to_del].friends[i]].posts[j].comment.end(),user_to_del);

				users[users[user_to_del].friends[i]].posts[j].comment.erase(it1);}
				}
				*/

				for(int k=0;k<users[users[user_to_del].friends[i]].posts[j].comment.size();k++){

					if(users[users[user_to_del].friends[i]].posts[j].comment[k].id==user_to_del){
						users[users[user_to_del].friends[i]].posts[j].comment.erase(k+users[users[user_to_del].friends[i]].posts[j].comment.begin());
					}

				}
			}


			for(int j=0;j<users[users[user_to_del].friends[i]].posts.size();j++)
			{

				while(find(users[users[user_to_del].friends[i]].posts[j].likes.begin(),users[users[user_to_del].friends[i]].posts[j].likes.end(),user_to_del)!=users[users[user_to_del].friends[i]].posts[j].likes.end())
				{
					auto it2=std::find(users[users[user_to_del].friends[i]].posts[j].likes.begin(),users[users[user_to_del].friends[i]].posts[j].likes.end(),user_to_del);

					users[users[user_to_del].friends[i]].posts[j].likes.erase(it2);
				}
			}




			



		}

	//	auto it3=std::find(users[users[user_to_del].friends[i]].id_friend_request.begin(),users[users[user_to_del].friends[i]].id_friend_request.end(),user_to_del);

		//	users[users[user_to_del].friends[i]].id_friend_request.erase(it3);
		users[user_to_del].posts.clear();
		users[user_to_del].friends .clear();
		users[user_to_del].waiting_acceptance .clear();
		users[user_to_del].id_friend_request .clear();

		free_ids.push_back(user_to_del);

		///if (std::find(users[this->id].friends.begin(), users[this->id].friends.end(),frnd)!=users[this->id].friends.end())



	}

	// these set functions are just used for testing and will be deleted 
	void setName(string name2)
	{
		name = name2;
	}
	void setId(int id2)
	{
		id = id2;
	}
	/*void setAge(string age2)
	{
		age = age2;
	}*/
	// these set functions are just used for testing and will be deleted 
	bool checkpost(int post){
		bool exist = false;
		for (int i = 0; i < users[this->id].posts.size(); i++){
			if (post == i){
				exist = true;
				break;
			}
		}
		return exist;
	}
	bool checkfrnd(int frnd){

		if (std::find(users[this->id].friends.begin(), users[this->id].friends.end(),frnd)!=users[this->id].friends.end())
		{
			return true;
		}
		else return false;

	}
	bool checksys(int frnd){
		//system exist checker
		bool exist = false;
		for (int i = 0; i < users.size(); i++){
			if (frnd == users[i].get_id()){
				exist = true;
				break;
			}
		}
		return exist;
	}
	XMLError user::LoadXML();
	friend class post;
};



user::user(int age, string name)
{

	
	this->name = name;
	this->age = age;
	if(free_ids.size()!=0){
		this->id = free_ids[free_ids.size()-1];
		
	}
	else{
		this->id = users_count;
		users_count++;
	}
}

int user::get_id(string find_name)
{

	for (int i = 0; i<users.size(); i++)
	{
		if (users[i].name == find_name)
		{
			return i;
			// break;
		}
	}

}

void user::add_friend(string name_to_add)
{
	int id_to_add = get_id(name_to_add);
	if (!checksys(id_to_add)){ cout << name_to_add << " doesn't exist\n"; }
	if (!checkfrnd(id_to_add)){ 
		//body of function
		
		users[id_to_add].id_friend_request.push_back(this->id);
	}
	else{ cout << name_to_add << " is already your friend\n"; }
	
}

void user::write_post(string write_post)
{
	post temp(write_post);
	posts.push_back(temp);
}

void user::preview_all_posts()
{

	for (int i = 0; i<posts.size(); i++)
	{
		cout << i << " : " ; posts[i].show_post(); cout<< endl;

	}

}


void user::like_f_post(int f_id, int f_post_id)
{

	if (users[f_id].posts.size() == 0){ cout << "your friend " << users[f_id].getName() << "has no posts yet\n"; }
	else{
		///check that if i liked it before
		if (std::find(users[f_id].posts[f_post_id].likes.begin(), users[f_id].posts[f_post_id].likes.end(),this->id)!=users[f_id].posts[f_post_id].likes.end())
		{
			cout<<"You already have liked it before"<<endl;
		}
		else{
		int store_id = this->id;
		cout << "you ";
		users[f_id].posts[f_post_id].like_post(store_id);
		cout << " like this post\n";
		}
	}

}


void user:: write_comment(string f_comment, int f_id, int f_post_id)//comment for friend's post
{

	users[f_id].posts[f_post_id].commenting(this->id /*da id bta3 men elly 3ml l comment ,,elly hoa called the function*/, f_comment);

}

void user::preview_profile()
{
	int my_id = (*this).get_id();
	cout << "My ID : " << my_id << endl;
	cout << "My username : " << users[my_id].name << endl;
	cout << "My age : " << users[my_id].age << endl;
	cout << "My friends : " << endl;
	for (int i = 0; i<users[my_id].friends.size(); i++)
	{
		cout << i << " : " << users[(users[my_id].friends[i])].name << endl;
	}

	cout << "My Posts : " << endl;
	users[my_id].preview_all_posts();
}

void user::preview_friend(string f_name)
{

	

	int f_id = get_id(f_name);

	if(checkfrnd(f_id))
	{
	cout << "ID : " << f_id << endl;
	cout << "Username : " << users[f_id].name << endl;
	cout << "Age : " << users[f_id].age << endl;
	cout << "Friends : " << endl;
	for (int i = 0; i<users[f_id].friends.size(); i++)
	{
		cout << i << " : " << users[(users[f_id].friends[i])].name << endl;
	}

	cout << "Posts : " << endl;
	users[f_id].preview_all_posts();
}
	else cout<<"This name is not your friend"<<endl;
}

int user::get_id()
{
	return this->id;
}

void user::delete_friend()
{
	string name_to_delete;
	if (users[this->id].friends.size() == 0){ cout << "you don't have any friends ya ba2es :P \n"; }
	else{
		cout << "enter friend name\n";

		cin >> name_to_delete;
		int id_to_del = get_id(name_to_delete);


		if (checkfrnd(id_to_del)){
			//body of function
		    auto it = find(users[this->id].friends.begin(), users[this->id].friends.end(), id_to_del); //5665
			users[this->id].friends.erase(it);
			auto it2 = find(users[id_to_del].friends.begin(), users[id_to_del].friends.end(),this->id);
			users[id_to_del].friends.erase(it2);
		}
		else{ cout << name_to_delete << " is not your friend\n"; }



	}
}
void user::delete_post()
{
	int post_index;
	
	if (users[this->id].posts.size() == 0){ cout << "you don't have any posts ya Negm :P \n"; }
	else{
		cout << "enter post ID\n";
		cin >> post_index;


		if (checkpost(post_index)){
			
			cout << users[this->id].posts[post_index].text << endl;//to be deleted
			users[this->id].posts.erase(posts.begin() + post_index);
		}
		else{ cout  << " can't find post\n"; }
	
	}
}
void user::accept_friend(){
	if (id_friend_request.size() != 0){
		for (int i = 0; i<id_friend_request.size(); i++){
			cout << users[id_friend_request[i]].name << endl;
			cout << "Accept:1 , Ignore:2 , Delete:3" << endl;
			int x;
			cin >> x;
			if (x == 1){
				users[this->id].friends.push_back(id_friend_request[i]);
				users[id_friend_request[i]].friends.push_back(this->id);
				cout<<users[id_friend_request[i]].name<<" now is your friend "<<endl;
				users[this->id].id_friend_request.erase(id_friend_request.begin() + i);
				

			}
			else if (x == 2);
			else if (x == 3){
				users[this->id].id_friend_request.erase(id_friend_request.begin() + i);

			}
		}

	}
	else if (id_friend_request.size() == 0)
	{
		cout << "No Friend requests yet\n";
	}

}
class syst{
	
	int userid;
	string  username;

public:
	syst(){};
	void setName(string name2){
		username = name2;
	}
	int findId(string myname){
		for (int i = 0; i < users.size(); i++){
			if (myname == users[i].getName()){
				
				return users[i].get_id();
			}
		}
		return 999;

	}
	string findname(int myid){
		for (int i = 0; i < users.size(); i++){
			if (myid == users[i].get_id()){

				return users[i].getName();
			}
		}
	}
	bool name_exist(string myname){
	
		for (int i = 0; i < users.size(); i++){
			if (myname == users[i].getName()){

				return true;
			}
		}
		return false;

	}
	void signin(){
		userid = findId(username);
		int choice;
		bool signout = false;
		int tempint;
		string tempstrg;
		do{
			cout << "----------------------\n";
			cout << "\n\n Welcome!! "<<username<<endl;
			cout << "enter 1 to write post\n";
			cout << "enter 2 to Delete post\n";
			cout << "enter 3 to Add friend\n";
			cout << "enter 4 to Delete friend\n";
			cout << "enter 5 to Accept Friend\n";
			cout << "enter 6 to view a Friend\n";
			cout << "enter 7 to view your posts\n";
			cout << "enter 8 to View Profile\n";
			cout << "enter 9 to write comment\n";
			cout << "enter 10 to like post\n";
			cout << "enter 11 to sign out\n";
			cin >> choice;
			switch (choice){
			case 1:
				cout << "enter post\n";
				getline(std::cin >> std::ws, tempstrg);
				users[userid].write_post(tempstrg);
				break;
			case 2:
				
				users[userid].delete_post();
				
				break;
			case 3:
				cout << "enter friend name\n";
				cin >> tempstrg;
				cout<<"Friend Request Sent"<<endl;
				users[userid].add_friend(tempstrg);
				break;
			case 4:
				users[userid].delete_friend();
				break;
			case 5:
				users[userid].accept_friend();
				break;
			case 6:
				cout << "enter friend name\n";
				cin >> tempstrg;
				users[userid].preview_friend(tempstrg);
				break;
			case 7:
				cout << "My Posts : " << endl;
				users[userid].preview_all_posts();
				break;
			case 8:
				users[userid].preview_profile();
				break;
			case 9:
				cout << "comment on : \n";
				cout << "Your own post : 1,\n";
				cout << "your Friend's post : 2\n";
				cin >> tempint; // errorhandle for empty input using do while
				
				if (tempint == 1){
					int postid;
					cout << "enter post number: \n";
					cin >> postid;

					cout << "write a comment : ... \n";
			    	getline(std::cin >> std::ws, tempstrg);

					users[userid].write_comment(tempstrg,userid,postid);



				}
				else if (tempint == 2){
					cout << "enter friend's name : \n";
					string s;
					cin>>s;
				tempint=user::get_id(s);
					
					int postid;
					cout << "enter post number: \n";
					cin >> postid;

					cout << "write a comment : ... \n";
			    	getline(std::cin >> std::ws, tempstrg);

					users[userid].write_comment(tempstrg,tempint,postid);
				}
				break;
			case 10:
				cout << "please enter your friend name : \n";
				cin >> tempstrg;
				tempint = findId(tempstrg);
				cout << "please enter your friend's post id : \n";
				int postid;
				cin >> postid;
				users[userid].like_f_post(tempint, postid);
				break;
			case 11: signout = true; break;
			}
		} while (!signout);
	}
	void adminMode(){
		userid = findId(username);
		int choice;
		bool signout = false;
		int tempint;
		string tempstrg;
		do{
			cout << "\n ---------Admin Mode------\n";
			cout << "\n\n Welcome !!\n";
			cout << "enter 1 to create user\n";
			cout << "enter 2 to Delete user\n";
			cout << "enter 3 to Delete user friend\n";
			cout << "enter 4 to Delete post\n";
			cout << "enter 5 to view user posts\n";
			cout << "enter 6 to View user Profile\n";
			cout << "enter 7 to write comment\n";
			cout << "enter 8 to like post\n";
			cout << "enter 9 to sign out\n";
			cin >> choice;
			switch (choice){
				{ case 1:
							bool unique = false;
							int name_counter = 1;
							string ok = "n";
							do{
								cout << "Enter user Name: \n";
								cin >> tempstrg;
								if (name_exist(tempstrg)){
									cout << "Name is already taken! \n\n";
									string suggest_name;
									do{
										ok = "n";
										char numstr[21]; // enough to hold all numbers up to 64-bits
										sprintf_s(numstr, "%d", name_counter);
										suggest_name = tempstrg + numstr;
										if (findId(suggest_name) == 999){
											unique = true;
											cout << "suggested name '" << suggest_name << "' proceed? (y/n)" << endl;
											cin >> ok;
											if (ok == "y" || ok == "Y"){
												tempstrg = suggest_name;
											}
										}
										name_counter++;
									} while (!unique);
								}
								else{
									ok = "y";
								}
							} while (ok == "n" || ok == "N");
							cout << "user  name is " << tempstrg << endl;
							cout << "Enter user Age: \n";
							cin >> tempint;
							if(free_ids.size()==0){
							user temp(tempint, tempstrg);
							users.push_back(temp);
						
							}
							else{
								int exist_id = free_ids[free_ids.size()-1];
								user temp(tempint, tempstrg);
								free_ids.pop_back();
								users[exist_id]=temp;
							}
							/*	if(free_ids.size()!=0){
		this->id = free_ids[free_ids.size()-1];
		free_ids.pop_back();
	}fat
	else{*/
							break; 
						}
			case 2:
							cout << "Enter user name : ";
							cin >> tempstrg;
							if (name_exist(tempstrg))
							{
								int user_to_del;
								user_to_del = user::get_id(tempstrg);
							//	auto it = find(users.begin(), users.end(), user_to_del); //5665
							//	users.erase(users.begin()+user_to_del);
								
								user::delete_user(user_to_del);
								cout << "user is deleted \n";
							}
							else { cout << "user not found! \n";}
							break;
			case 3:
							cout << "Enter user name : ";
							cin >> tempstrg;
							if (name_exist(tempstrg))
							{
				
								userid = findId(tempstrg);
								users[userid].delete_friend();
		
							}
							else { cout << "user not found! \n";}
							break;
			case 4:
							cout << "Enter user name : ";
							cin >> tempstrg;
							if (name_exist(tempstrg))
							{
								userid = findId(tempstrg);
								users[userid].delete_post();
							}
							else { cout << "user not found! \n";}
							break;
			case 5:
							cout << "Enter user name : ";
							cin >> tempstrg;
							if (name_exist(tempstrg))
							{
								userid = findId(tempstrg);
								cout << "My Posts : " << endl;
								users[userid].preview_all_posts();
							}
							else { cout << "user not found! \n";}
							break;
			case 6:
							cout << "Enter user name : ";
							cin >> tempstrg;
							if (name_exist(tempstrg)){
								userid = findId(tempstrg);
								users[userid].preview_profile();
							}
							else { cout << "user not found! \n";}
							break;
			case 7:break;
			case 8:break;
			case 9: signout = true; break;
			}
		} while (!signout);
		
	}
};



void post:: show_post(/*int user_id, int post_id*/){

		cout<<this->text<<endl;
		cout<<"likes : "<<likes.size()<<endl;
		cout<<"Comments : "<<comment.size()<<endl;

		for(int i=0;i<comment.size();i++)
		{
			cout<<users[comment[i].id].getName()<<" : "<<comment[i].comment<<endl;
		}
	}
XMLError user::LoadXML()
{
	XMLDocument DS;
	XMLError eResult = DS.LoadFile("DataBase.xml");
	XMLCheckResult(eResult);
	XMLNode * system = DS.FirstChild();
	if (system == nullptr) cout << "what system? \n";
	XMLElement * Users = system->FirstChildElement("Users");
	if (Users == nullptr) cout << "what users? \n";
	XMLElement * User = Users->FirstChildElement("User");
	if (User == nullptr) cout << "what single user? \n";
	while (User != nullptr)
	{
		int id, age;
		string name;
		eResult = User->QueryIntAttribute("ID", &id);
		XMLCheckResult(eResult);
		eResult = User->QueryIntAttribute("age", &age);
		XMLCheckResult(eResult);
		const char * tempText = nullptr;
		tempText = User->Attribute("name");
		if (tempText == nullptr) cout << "what name? \n";
		name = tempText;
		cout << id << "  " << name << " " << age << endl;
		user temp(age, name);

		//----- getting posts----//
		XMLElement * Posts = User->FirstChildElement("Posts");
		if (Posts == nullptr) cout << "what Posts? \n";
		XMLElement * Post = Posts->FirstChildElement("Post");
		if (Post == nullptr) cout << "what single Post? \n";
		while (Post != nullptr){

			int pid;
			string text;
			eResult = Post->QueryIntAttribute("ID", &pid);
			XMLCheckResult(eResult);
			const char * tempText2 = nullptr;
			tempText2 = Post->GetText();
			text = tempText2;
			cout << text << endl;
			post temppost(text);
			temp.posts.push_back(temppost);
			cout << temp.posts[pid].show_post() << endl;
			//----- getting Likes----//	
			XMLElement * Likes = Post->FirstChildElement("likes");
			if (Likes == nullptr) cout << "what Likes? \n";
			XMLElement * liker = Likes->FirstChildElement("liker");
			if (liker == nullptr) cout << "what single liker? \n";
			while (liker != nullptr){
				int Lid;
				eResult = liker->QueryIntText(&Lid);
				XMLCheckResult(eResult);
				temp.posts[pid].likes.push_back(Lid);
				liker = liker->NextSiblingElement("liker");
			}

			//---------finish likes-----//
			//----- getting Comments----//	
			XMLElement * Comments = Post->FirstChildElement("comments");
			if (Comments == nullptr) cout << "what comments? \n";
			XMLElement * comment = Comments->FirstChildElement("comment");
			if (comment == nullptr) cout << "what single comment? \n";
			while (comment != nullptr){
				int frindID;
				string comntText;
				eResult = comment->QueryIntAttribute("frindID", &frindID);
				XMLCheckResult(eResult);
				const char * tempText2 = nullptr;
				tempText2 = comment->GetText();
				comntText = tempText2;
				comments tempcomnt;
				tempcomnt.comment = comntText;
				tempcomnt.id = frindID;
				temp.posts[pid].comment.push_back(tempcomnt);
				comment = comment->NextSiblingElement("comment");
			}
			//---------finish Comments-----//

			Post = Post->NextSiblingElement("Post");
		}
		//---------finish posts-----//
		//----- getting friend req----//
		XMLElement * FriendRequests = User->FirstChildElement("FriendRequests");
		if (FriendRequests == nullptr) cout << "what FriendRequests? \n";
		XMLElement * Request = FriendRequests->FirstChildElement("Request");
		if (Request == nullptr) cout << "what single Request? \n";
		while (Request != nullptr){
			int Rid;
			eResult = Request->QueryIntAttribute("ID", &Rid);
			XMLCheckResult(eResult);
			temp.id_friend_request.push_back(Rid);
			Request = Request->NextSiblingElement("Request");
		}

		//---- finish friend req --//
		//----- getting friends----//

		XMLElement * Friends = User->FirstChildElement("Friends");
		if (Friends == nullptr) cout << "what Friends? \n";
		XMLElement * Friend = Friends->FirstChildElement("Friend");
		if (Friend == nullptr) cout << "what single Friend? \n";

		while (Friend != nullptr){
			int Fid;
			eResult = Friend->QueryIntAttribute("ID", &Fid);
			XMLCheckResult(eResult);
			temp.friends.push_back(Fid);
			Friend = Friend->NextSiblingElement("Friend");
		}


		//---- finish friends--//

		users.push_back(temp);

		User = User->NextSiblingElement("User");
	}
}
int main()
{
	bool exit = false;
	int index;
	syst def;
	user A, B;
	post temp2("Temp post");
	temp2.pid = 1000;
	string temp;
	//A.setName("osama");
//	A.setId (0);
//	B.setName ("gomaa");
	//B.setId (1);
	
	//users.push_back(A);
	//users.push_back(B);
	

	do{
		cout << "enter 1 for admin\n";
		cout << "enter 2 for user\n";
		cout << "enter 3 to exit\n";
			cin >> index;
			if (index == 1){ def.adminMode();
			}
		else if(index==2){
			cout << "sign in with your name\n";
			cin >> temp;
			def.setName(temp);
			def.signin();
		}
		else{
			exit = true;
		}
	} while (!exit);
	return(0);
}