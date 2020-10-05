
example2.o: web++.o web++.o gerdabServer.o api.o gerdabPlayer.o rated.o music.o album.o place.o database.o artist.o admin.o user.o queue.o logic.o homeplace.o albumplace.o musicplace.o libraryplace.o homehandler.o signuphandler.o loginhandler.o searchhandler.o musichandler.o albumhandler.o artisthandler.o playlistshandler.o playlisthandler.o artistplace.o example2.cpp gerdabServer.hpp
	g++ -std=c++11 web++.o gerdabServer.o api.o gerdabPlayer.o rated.o music.o album.o place.o database.o artist.o admin.o user.o queue.o logic.o homeplace.o albumplace.o musicplace.o libraryplace.o homehandler.o signuphandler.o loginhandler.o searchhandler.o musichandler.o albumhandler.o artisthandler.o playlistshandler.o playlisthandler.o artistplace.o example2.cpp -l SDL2_mixer -o example1.out

gerdabPlayer.o: gerdabPlayer.cpp
		g++ -std=c++11 -c gerdabPlayer.cpp

rated.o: rated.h rated.cpp
	g++ -c rated.cpp

music.o: music.h rated.h music.cpp
	g++ -c music.cpp

album.o: album.h rated.h album.cpp
	g++ -c album.cpp

place.o: place.h logic.hpp place.cpp
	g++ -c place.cpp

database.o: database.h music.h database.cpp
	g++ -c database.cpp

artist.o: artist.h database.h user.h rated.h artist.cpp
	g++ -c artist.cpp


admin.o: admin.cpp user.h rated.h database.h admin.h 
	g++ -c admin.cpp

user.o: user.h playlist.h place.h user.cpp
	g++ -c user.cpp -l SDL2_mixer

queue.o: queue.h queue.cpp
	g++ -c queue.cpp -l SDL2_mixer

logic.o: logic.hpp artist.h logic.cpp
	g++ -c logic.cpp

api.o: api.hpp api.cpp
	g++ -c api.cpp

homeplace.o: playlistplace.h homeplace.cpp
	g++ -c homeplace.cpp

albumplace.o: albumplace.h albumplace.cpp
	g++ -c albumplace.cpp

musicplace.o: musicplace.h musicplace.cpp
	g++ -c musicplace.cpp

libraryplace.o: libraryplace.h libraryplace.cpp
	g++ -c libraryplace.cpp

artistplace.o: artistplace.h artistplace.cpp
	g++ -c artistplace.cpp

homehandler.o: homehandler.h homehandler.cpp
	g++ -c homehandler.cpp

signuphandler.o: signuphandler.h signuphandler.cpp
	g++ -c signuphandler.cpp

loginhandler.o: loginhandler.h loginhandler.cpp
	g++ -c loginhandler.cpp

searchhandler.o: searchhandler.h searchhandler.cpp
	g++ -c searchhandler.cpp

albumhandler.o: albumhandler.h albumhandler.cpp
	g++ -c albumhandler.cpp

artisthandler.o: artisthandler.h artisthandler.cpp
	g++ -c artisthandler.cpp

playlistshandler.o: playlistshandler.h playlistshandler.cpp
	g++ -c playlistshandler.cpp

playlisthandler.o: playlisthandler.h playlisthandler.cpp
	g++ -c playlisthandler.cpp

musichandler.o: musichandler.h musichandler.cpp
	g++ -c musichandler.cpp

gerdabServer.o: gerdabServer.cpp
		g++ -std=c++11 -c gerdabServer.cpp -o gerdabServer.o

web++.o: web++.cpp
		g++ -std=c++11 -c web++.cpp -o web++.o


clean: 
	rm -rf *o example1.out