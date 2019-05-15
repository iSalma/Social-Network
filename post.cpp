
#include <iostream> 
#include <string>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
#include "post.h"// mesh 3arfa leah
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
	post(string text)
	{
		this->text = text;

	}
	void like_post(int f_id) {
	
		likes.push_back(f_id);
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
		int pos;
		
			
		// Element to be searched

		// std::find function call
		it = std::find(likes.begin(), likes.end(), f_id);
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
		std::vector<int>::iterator it;
		it = std::find(likes.begin(), likes.end(), temp);
		comment.erase(std::remove(comment.begin(), comment.end(), *it), comment.end());
	}

	string show_post() {

		return this->text;

		
	}



	/*string show_post() {
		string p="", c="";
		int l;
		p = text;
		l = total_likes();
		for (int i = comment.size() - 1; i > -1; i--) {

			comments temp = comment[i];
			int temp1 = temp.id;
			string temp2 = temp.comment;
			c += my_map[temp1] + '+' + temp2+'/n';// assume my map by ids
		
		}
		return p + "/n" + to_string(l)+ "/n" + c;
	}
	string show_likes() {
		string c;
		for (int i = likes.size() - 1; i > -1; i--)
		{
		int temp1=
			c += my_map[temp1]+'/n';// assume my map by ids

		}*/
	}

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


};
