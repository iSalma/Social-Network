#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class post
{
private:
	 string text;
	vector <int> likes;
	//vector <comments> comment;

public:

	post(string text)
		{
			this->text=text;
			
	}// constructor
	void like_post(int f_id) {
	
		likes.push_back(f_id);
	}
	void delete_like(int f_id);
	
	int total_likes() {
		return likes.size();
	}
	void commenting(int f_id, string f_comment);//add comment to post & who write it in comment vector
	int comment_count(void);//count total number of comments
	void delete_comment(int f_id,string f_comment);
///	string show_post();// show post string & its likes & comments 
	string show_post() {

		return this->text;

		
	}


	friend class user;
};

class user {
private:
	 int id;
	string name;
	vector<post> posts;


public:

	user(int id, string name)
	{
		this->id=id;
		this->name=name;
	}

	string get_name()
	{
		return name;
	}
	static int  get_id(string find_name);

	void  write_post(string w_post)
{
	post temp(w_post);
	posts.push_back(temp);
}
	void  preview_post();

	void like_f_post(int f_id, int f_post_id);

};

vector<user>users;
int main()
{
	

	user u1=user(1,"roba");
	users.push_back(u1);
	user u2=user(2,"salma");
	users.push_back(u2);

	user u3=user(3,"fatma");
	users.push_back(u3);

	string to_find="fatma";
///	auto it = find_if(users.begin(), users.end(), [&to_find](const user& obj) {return obj.get_name() == to_find;})
	//cout<<user::get_id("roba");

	u1.write_post("hi there"); 
	u2.write_post("bye b2a");
	
	
	u1.like_f_post(1,0);
	u1.preview_post();
	

}

int user:: get_id(string find_name)
{

	for (int i=0; i<users.size(); i++)
	{
	   if (users[i].name==find_name)
	   {
		   return i;
	   }
	}
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
		//cout<<"likes="<<posts[i].total_likes();

	}
	cout<<"likes="<<posts[0].total_likes();


}	


 void user:: like_f_post(int f_id, int f_post_id)
{


	int store_id=this->id;

   users[f_id].posts[f_post_id].like_post(store_id);


}