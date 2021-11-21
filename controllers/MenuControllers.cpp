void ButtonWriter(int btnCode){
	using std::cout;

	if(btnCode == ID_FILE_EXIT){
		cout << "Get out!!\n";
	}else{
		cout << "the button clicked is: " << btnCode << "\n";
	}

	if(btnCode == 302){
		cout << "here I should open a html file in browset\n";

		ShellExecute(NULL, "open", "wiki.html",
                NULL, NULL, SW_SHOWNORMAL);
	}
}

void OpenLocalFile(int btnCode){
	using std::cout;

	if((btnCode == OPEN_FILE_ID) || (btnCode == NEW_FILE_ID)){
		cout << "this command is for opening files\n";
	}else{
		cout << "that item does not require opening files\n";
	}
}