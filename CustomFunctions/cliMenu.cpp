void createMenu(string message, string options[])
{
	cout << message << "\n";
	int i = 0;
	while(options[i] != "end")
	{
		cout << i << ". " << options[i++] << "\n"; 
	}
}
