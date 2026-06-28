#ifdef __XENONIUM_ENTRY_POINT

int main(int argc, char* argv[]) {
	Xenonium::Game* game = Xenonium::CreateGame();
	
	game->Initialize();
	game->Run();

	int code = game->GetReturnCode();

	delete game;
	return code;
}
#endif