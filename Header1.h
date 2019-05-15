#pragma once


#include <iostream> 
#include <string>
#include <vector>

using namespace std;
struct comments
{
 	int id;
	string comment;
};
class post
{
private:
	string text;
	vector <int> likes;
	vector <comments> comment;

public:
	post(string text);// constructor
	void like_post(int f_id);// add friend id to like list
	void delete_like(int f_id);
	int total_likes();//count total likes for a post
	void commenting(int f_id, string f_comment);//add comment to post & who write it in comment vector
	int comment_count(void);//count total number of comments
	void delete_comment(int f_id,sting f_comment);
	string show_post();// show post string & its likes & comments 

};
class user {
private:
	 int id;
	string name;
	string age;//can be int but separate it in days/month/year
	static int users_count=0;

	vector<post> posts;
	vector<int>friends;
	vector<int>id_friend_request;
	vector<int>waiting_acceptance;
	bool flag_user = 0;


public:
	user(int age, string name);//constructor 
	 signIn(int id /*password can be added*/); /// return pointer to this user //to implement in system
	void accept_friend(int id);//see list of request & preview data & decide accept(make sure to delete it from request list) or no
	void add_friend(int id/*or use his name*/);//wait for acceptance & add it to waiting list
	void write_post(string post);
	void preview_post();
	static int get_id(string find_name);


	void like_f_post(int f_id, int f_post_id);
	void comments write_comment(string comment, int f_post_id);//comment for my own posts
	comments write_comment(string comment,int f_id, int f_post_id);//comment for friend's post
	void preview_profile();//preview user data/friends names/post (can specialize it for friend & not friend
	void preview_friend(int f_id); //preview friend data + friend posts
	void delete_friend(int id);
	void delete_post(int index/*string post Or anything which is distinguish*/);
	
	
};


user::user(int age, string name)
{

	this->id=user_counter;
	this->name=name;
	this->age=age;

	user_counter++;

}

 int user:: get_id(string find_name)
{

	for (int i=0; i<users.size(); i++)
	{
	   if (users[i].name==find_name)
	   {
		   return i;
		  // break;
	   }
	}

}


void user:: add_friend(string name_to_add)
{
	int id_to_add=get_id(name_to_add);

	friends.insert(id_to_add);
	

}



void user:: write_post(string write_post)
{
	post temp(write_post);
	posts.push_back(temp);
}



void user:: preview_post()
{
	/*for(int i=0;i<posts.size();i++)
	{
		cout<< posts[i].text;

	}*/

	for(int i=0;i<posts.size();i++)
	{
		cout<<posts[i].show_post()<<endl;

	}

	
}	


 void user:: like_f_post(int f_id, int f_post_id)
{


	int store_id=this->id;

   users[f_id].posts[f_post_id].like_post(store_id);


}
