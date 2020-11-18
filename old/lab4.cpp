/*
Laboratory #4: Arrays
Submit Date: February 27th, 2017

Group Name: Los Paralelepipedos
Group Members:
1) Pablo Alexis Domínguez Grau
2) José Luis Ojeda De Leon
*/


// Mostrar nombre de articulos
// Mostrar cantidad de articulos
// Permitir quitar articulos en el carrito de compras
// Simplificar codigo - funciones

/// Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>

/// Definitions
#define INVALID_SELECTION "\nEnter a valid selection: "
#define INVALID_QUANTITY "\nEnter a valid quantity: "
#define ITEM_ADDED "\nThis item has been added to the cart.\n"
#define INITIALIZE "Go back to the main menu"
#define INITIALIZE_TV cout << "\t6) Go back to the TV brands menu\n\n" << "Select the TV you would like to buy: ";
#define INITIALIZE_PHONE(x) cout << "\t" << x << ") Go back to the Phone brands menu" << endl << endl << "Select the smartphone you would like to buy: ";
#define PAUSE system("pause")
#define CLEAR system("cls")
#define MAX_TV_ID 25
#define MAX_PHONE_ID 48
#define MAX_VIDEOGAME_ID 78
#define MAX_MOVIE_ID 128
#define MAX_BOOK_ID 148
#define MAX_ID = 148
#define UPDATE_ID_LIST h++; i = 0;
#define LOOP_ID_UPDATE_1 j = 0; y++;
#define SHOW_PHONES for (int i = 0; i < PHONES; i++) { if (PhonePrices[brand][i] != 0) { cout << "\t" << i + 1 << ") " << PhonesNames[brand][i] << setw(5) << "$" << PhonePrices[brand][i] << endl;}}
#define SHOW_TVS for (int i = 0; i < TV; i++) {  cout << "\t" << i + 1 << ") " << TVNames[brand][i] << setw(5) << "$" << TVPrices[brand][i] << endl; }

/// Namespace
// STD stands for std:: (standard)
using namespace std;

/// Prototypes
// Main Menu and Exit functions prototypes
void Menu();
void Goodbye();

// Televisions prototypes
int Televisions(int);
int TV_Samsung(int);
int TV_Vizio(int);
int TV_Sony(int);
int TV_LG(int);
int TV_Sharp(int);
void TelevisionsMenu();
void TVCounter(int &, int &, int &, int, short int);
void StoreTVSelected(short int, int, short int);
void TVExitMessage(int, short int);

// Phones prototypes
int Smartphones(int);
int Apple_Phone(int);
int Samsung_Phone(int);
int HTC_Phone(int);
int LG_Phone(int);
int Sony_Phone(int);
void PhoneCounter(int &, int &, int &, int, short int);
void PhoneExitMessage(int, short int);
void PhoneMenu();
void StorePhoneSelected(short int, int, short int);

// Videogame prototype
int Videogames(int, int);
void VideogameCounter(int &, int &, int &, short int);
void StoreVideogameSelected(short int, int);

// Movies prototypes
double Movies(double, double);
void MovieCounter(int &, double &, double &, short int, short int);
void StoreMovieSelected(short int, int, short int);

// Book prototype
int Books(int, int);
void BookCounter(int &, int &, int &, short int, short int);
void StoreBookSelected(short int, int, short int);


// Cart's prototypes
double Cart(int, int, int, double, int, bool);
void ShowItems(int, int, int, double, int);
void RemovalQuestion(int &, int &, int &, double &, int &);
void ShowRemovableItems(int &, int &, int &, double &, int &);
void ItemRemoval(int, int &, int &, int &, int &, double &, int &);
void ResetSearchPosition(int &, int &);
void QuantityRemovalValidation(int, int &, int &, bool &);
void Outputs(double, double, double, double, double, double, double);
void Receipt(int, int, int, double, int);
void TypeOfPayments();


/// Public variables, strings, and arrays
const short int TOTAL_ITEMS = 148,
TV = 5, TV_AMOUNT = 25,
PHONES = 5, PHONES_AMOUNT = 23,
VIDEOGAMES = 30, VIDEOGAMES_AMOUNT = 30,
MOVIES = 25, MOVIES_AMOUNT = 25, MOVIE_TYPES = 2,
BOOKS = 20, BOOKS_AMOUNT = 20, MAX_BOOK_BY_AUTHOR = 7, AUTHORS = 8;
short int CartOK = 0;


// String arrays to hold the name of each item.

string TVBrands[TV] =
{ "Samsung",
"Vizio",
"Sony",
"LG",
"Sharp", };

string TVNames[TV][TV] = {

	// Samsung TVs are stored in the row 0
	{ "Samsung 78\" LED Curved - Smart 4K Ultra HD/HDR       ",
	"Samsung 75\" LED 3D - Smart 4K Ultra HD               ",
	"Samsung 60\" LED - Smart 4K Ultra HD/HDR              ",
	"Samsung 55\" LED - Smart 4K Ultra HD/HDR              ",
	"Samsung 49\" LED - Smart 4K Ultra HD/HDR              " },

	// Vizio TVs are stored in the row 1
	{ "Vizio 75\" LED - Smart 4K Ultra HD/HDR/Chromecast     ",
	"Vizio 65\" LED - Smart 4K Ultra HD/HDR/Chromecast     ",
	"Vizio 55\" LED - Smart 4K Ultra HD/HDR/Chromecast     ",
	"Vizio 65\" LED - Smart 4K Ultra HD                    ",
	"Vizio 49\" LED - Smart 4K Ultra HD                    " },

	// Sony TVs are stored in the row 2
	{ "Sony 75\" LED - Smart 4K Ultra HD/HDR/Chromecast      ",
	"Sony 65\" LED - Smart 4K Ultra HD/HDR/Chromecast      ",
	"Sony 55\" LED - Smart 4K Ultra HD/HDR/Chromecast      ",
	"Sony 55\" LCD - Smart 4K Ultra HD/HDR                 ",
	"Sony 43\" LED - Smart 4K Ultra HD/HDR/Chromecast      " },

	// LG TVs are stored in the row 3
	{ "LG 65\" OLED 3D - Smart 4K Ultra HD with HDR          ",
	"LG 65\" OLED - Smart 4K Ultra HD with HDR             ",
	"LG 55\" OLED - Smart 4K Ultra HD with HDR             ",
	"LG 60\" LED - Smart 4K Ultra HD with HDR              ",
	"LG 50\" LED - Smart 4K Ultra HD                       " },

	// Sharp TVs are stored in the row 4
	{ "Sharp 65\" LED - Smart 4K Ultra HD with Web Browser   ",
	"Sharp 55\" LED - Smart 4K Ultra HD with Web Browser   ",
	"Sharp 55\" LED - Smart Full HD with Roku              ",
	"Sharp 50\" LED - Smart Full HD with Roku              ",
	"Sharp 43\" LED - Smart Full HD with Roku              " } };

string PhoneBrands[PHONES] =
{ "Apple",
"Samsung",
"HTC",
"LG",
"Sony" };

string PhonesNames[PHONES][PHONES] =
{
	{ "iPhone 7 Plus 5.5\" - 256GB - 4 Core Apple A10        ",
	"iPhone 7 4.7\" - 256GB - 4 Core Apple A10             ",
	"iPhone 6S Plus 5.5\" - 128GB - 2 Core Apple A9        ",
	"iPhone 6S 4.7\" - 128GB - 2 Core Apple A9             ",
	"iPhone SE - 4.0\" - 64GB - 2 Core Apple A9            " },

	{ "Samsung Galaxy Note 5 5.7\" - 64GB Storage            ",
	"Samsung Galaxy S7 Edge 5.5\" - 32GB Storage           ",
	"Samsung Galaxy S7 5.1\" - 32GB Storage                ",
	"Samsung Galaxy S6 Edge+ 5.7\" - 64GB Storage          ",
	"Samsung Galaxy S6 5.1\" - 128GB Storage               " },

	{ "HTC U Ultra 5.7\" - 64GB - 4 Core Snapdragon 821      ",
	"HTC M10 5.2\" - 32GB - Quad Core Snapdragon 820       ",
	"HTC Bolt 5.5\" - 32GB - Octa Core Snapdragon 810      ",
	"HTC A9 5.0\" - 32GB - Octa Core Snapdragon 627        " },

	{ "LG G4 5.5\" - 32GB Storage                            ",
	"LG V10 5.7\" - 64GB Storage                           ",
	"LG G3 5.5\"  - 32GB Storage                           ",
	"LG G5 SE 5.3\" - 32GB Storage                         ",
	"LG X Power 5.3\"  16GB Storage                        " },

	{ "Sony Xperia XZ 5.2\" - 32GB Storage                   ",
	"Sony Xperia X Compact 4.6\" - 32GB Storage            ",
	"Sony Xperia X Performance 5\" - 32GB Storage          ",
	"Sony Xperia XA Ultra 6\" - 16GB Storage               " }
};

string VideogamesNames[VIDEOGAMES] =
{ "Forza Horizon 3                                      ",
"Final Fantasy XV                                     ",
"Doom                                                 ",
"Destiny                                              ",
"Assassins Creed Syndicate                            ",
"Fallout 4                                            ",
"Forza Motorsport 6                                   ",
"Assassins Creed Unity                                ",
"Watch Dogs                                           ",
"Overwatch                                            ",
"Forza Horizon 2                                      ",
"Rise: Son of Rome                                    ",
"The Witcher III: Wild Hunt                           ",
"Mortal Kombat X                                      ",
"Call of Duty: Ghosts                                 ",
"Halo: The Masterchief Collection                     ",
"Star Wars: Battlefront                               ",
"Grand Theft Auto V                                   ",
"Injustice: Gods Among Us                             ",
"Assassins Creed IV: Black Flag                       ",
"Batman: Arkham Knight                                ",
"Halo 5                                               ",
"The Titanfall                                        ",
"Mass Effect Collection (3-Games)                     ",
"Mortal Kombat Complete Edition                       ",
"Batman Arkham: Origins                               ",
"Assassins Creed Revelation                           ",
"Tomb Rider                                           ",
"Super Mario 3D World                                 ",
"Pikmin 3                                             " };

string MoviesNames[MOVIES] =
{ "I, Robot                                             ",
"Battle: Los Angeles                                  ",
"Inside Out                                           ",
"The Fault in Our Stars                               ",
"Monster House                                        ",
"Yogi Bear (2-Movie Collection)                       ",
"Deadpool                                             ",
"The Martian                                          ",
"Nightmare Before Christmas                           ",
"The Secret Life of Pets                              ",
"Willy Wonka and the Chocolate Factory                ",
"Guardians of the Galaxy                              ",
"Wreck-it Ralph                                       ",
"Pirates of the Caribbean (5-Movie Collection)        ",
"Suicide Squad                                        ",
"Batman vs. Superman                                  ",
"The Twilight Saga (4-Movie Collection)               ",
"Percy Jackson & The Olympians (2-Movie Collection)   ",
"Lord of the Rings (3-Movie Collection)               ",
"Transformers (5-Movie Collection)                    ",
"X-Men (9-Movie Collection)                           ",
"Harry Potter (8-Movie Collection)                    ",
"Alvin and the Chipmunks (4-Movie Collection)         ",
"Ice Age (5-Movie Collection)                         ",
"Star Wars: The Complete Saga (8-Movie Collection)    " };

string BooksNames[AUTHORS][7] = {

	//Isabel Allende
	{ "Maya's Notebook                                      ",
	"Ripper                                               ",
	"The House of the Spirits                             ",
	"City of the Beasts (2-Book Set)                      " },

	// Paulo Coelho
	{ "Veronika Decides to Die                              ",
	"The Devil and Miss Prym                              ",
	"By the River Piedra I Sat Down and Wept              ",
	"The Alchemist                                        ",
	"The Zahir                                            ",
	"Brida                                                ",
	"The Witch of Portobello                              " },

	// John Green
	{ "Let It Snow (with L. Myracle & M. Johnson)           ",
	"Abundance of Katherines                              ",
	"The Fault in Our Stars                               ",
	"Paper Towns                                          " },

	// Gabriel Garcia Marquez
	{ "One Hundred Years of Solitude                        " },

	// Homero
	{ "The Iliad                                            " },

	// Richard Russell Riordan
	{ "Percy Jackson & The Olympians (5-Book Set)           " },

	// Ransom Riggs
	{ "Miss Peregrine's (3-Book Set)                        " },

	// Stephenie Meyer
	{ "The Twilight Saga (4-Book Set)                       " } };

string AuthorsNames[AUTHORS] = {
	"Isabel Allende", "Paulo Coelho",
	"John Green", "Gabriel Garcia Marquez",
	"Homero", "Richard Rusell Riordan",
	"Ransom Riggs", "Stephenie Meyer" };

// Arrays to hold the ID of every item, in their respective category.
short int ITEMS_ID[5][50] = {

	// TVs ID
	{ 1, 2, 3, 4, 5,
	  6, 7, 8, 9, 10,
	  11, 12,	13, 14, 15,
	  16, 17, 18,	19, 20,
	  21, 22, 23, 24, 25 },

	// Phones ID
	{ 26, 27, 28, 29, 30,
	31, 32, 33, 34, 35, 36,
	37, 38, 39, 40, 41, 42,
	43, 44, 45, 46, 47, 48 },

	// Videogames ID
	{ 49, 50, 51, 52, 53,
	54, 55, 56, 57, 58,
	59, 60, 61, 62, 63,
	64, 65, 66, 67, 68,
	69, 70, 71, 72, 73,
	74, 75, 76, 77, 78 },

	// Movies ID
	{ 79, 80, 81, 82, 83,
	84, 85, 86, 87, 88,
	89, 90, 91, 92, 93,
	94, 95, 96, 97, 98,
	99, 100, 101, 102, 103,
	104, 105, 106, 107, 108,
	109, 110, 111, 112, 113,
	114, 115, 116, 117, 118,
	119, 120, 121, 122, 123,
	124, 125, 126, 127, 128 },

	// Books ID
	{ 129, 130, 131, 132, 133,
	134, 135, 136, 137, 138,
	139, 140, 141, 142, 143,
	144, 145, 146, 147, 148 } };

// Arrays to hold the selected items.
unsigned int TVSelected[TV][TV] = { { 0 } };
unsigned int PhoneSelected[PHONES][PHONES] = { { 0 } };
unsigned int VideogamesSelected[VIDEOGAMES_AMOUNT] = { 0 };
unsigned int MoviesSelected[2][MOVIES] = { { 0 } };
unsigned int BookSelected[AUTHORS][7] = { { 0 } };

/// Arrays to hold prices
// Array of TV Prices
const short int TVPrices[TV][TV] = {

	//  Samsung TVs are stored in the row 0
	{ 4000, 2600, 2000, 1200, 800 },

	// Vizio TVs are stored in the row 1
	{ 3700, 1900, 1100, 780, 400 },

	// Sony TVs are stored in the row 2
	{ 5000, 4000, 2400, 1100, 1000 },

	// LG TVs are stored in the row 3
	{ 1000, 650, 450, 400, 300 },

	// Sharp TVs are stored in the row 4
	{ 4500, 4000, 2500, 1300, 650 } };

// Array of Phone Prices
const short int PhonePrices[PHONES][PHONES] = {

	// Apple Prices are stored in the row 0
	{ 969, 849, 749, 649, 449 },

	// Samsung Prices are stored in the row 1
	{ 839, 795, 695, 599, 495 },

	// HTC Prices are stored in the row 2
	{ 749, 699, 600, 499 },

	// LG Prices are stored in the row 3
	{ 650, 630, 600, 395, 240 },

	// Sony Prices are stored in the row 4
	{ 699, 649, 550, 330 } };

// Array of Videogame Prices
const short int VideogamesPrices[VIDEOGAMES] =
{ 80, 60, 60, 60, 60,
60, 60, 60, 60, 60,
50, 50, 50, 40, 40,
30, 30, 25, 25, 25,
20, 20, 20, 20, 20,
20, 20, 20, 15, 15 };

// Array of Movie Prices
const float MoviesPriceDVD_BLURAY[2][MOVIES] = {

	// DVD movie prices are stored in the row 0
	{ 6, 8, 8, 8, 10, 10,
	10, 10, 10, 15, 15,
	15, 15, 25, 25, 25,
	25, 30, 30, 30, 40,
	40, 40, 50, 75 },

	// BluRay movie prices are stored in the row 1
	{ 7.5, 10, 10, 10, 12.5,
	12.5, 12.5, 12.5, 12.5, 18.75,
	18.75, 18.75, 18.75, 31.25, 31.25,
	31.25, 31.25, 37.5, 37.5, 37.5,
	50, 50, 50, 62.5, 93.75 } };

// Array of Book Prices
const short int BooksPrices[AUTHORS][7] = {

	// Isabel Allende book prices are stored in the row 0
	{ 15, 15, 25, 40 },

	// Paulo Coelho book prices are stored in the row 0
	{ 10, 10, 10, 10, 10, 10, 25 },

	// John Green book prices are stored in the row 0
	{ 12, 18, 20, 20 },

	// Gabriel Garcia Marquez book prices are stored in the row 0
	{ 22 },

	// Homero book prices are stored in the row 0
	{ 23 },

	// Richard Rusell Riourdan book prices are stored in the row 0
	{ 55 },

	// Ransom Riggs book prices are stored in the row 0
	{ 45 },

	// Stephenie Meyer book prices are stored in the row 0
	{ 50 } };

int main() {

	int Videogames_Cost = 0, Books_Cost = 0;
	double Movies_Cost = 0;

	int tv = 0, game = 0, book = 0, phone = 0, tv_pass = 0,
		game_pass = 0, phone_pass = 0, book_pass = 0;
	bool Back = false;
	double movie = 0, movies_pass = 0, Total = 0;
	short int MenuSelector;
	char Retry = 'Y';

	Menu();

	do {

		cin >> MenuSelector;

		switch (MenuSelector) {

		case 1:

			tv += Televisions(tv_pass);
			Menu();
			break;

		case 2:

			phone += Smartphones(phone_pass);
			Menu();
			break;

		case 3:
			game += Videogames(Videogames_Cost, game_pass);
			Menu();
			break;

		case 4:
			movie += Movies(Movies_Cost, movies_pass);
			Menu();
			break;

		case 5:
			book += Books(Books_Cost, book_pass);
			Menu();
			break;

		case 6:

			if (tv + phone + game + movie + book != 0) {
				Cart(tv, phone, game, movie, book, Back);

				if (Back) {
					Menu();
					break;
				}
				else {
					CLEAR;
					cout << "Would you like to visit our store again? (Y/N): ";
					cin >> Retry;

					if (Retry == 'Y' || Retry == 'y') {
						tv = 0, game = 0, book = 0, movie = 0, phone = 0, Back = false;

						for (int i = 0; i < TV; i++) {
							for (int j = 0; j < TV; j++) {
								if (TVSelected[j][i] != 0) {
									TVSelected[j][i] = { 0 };
								}
							}
						}
						for (int i = 0; i < PHONES; i++) {
							for (int j = 0; j < PHONES; j++) {
								if (PhoneSelected[j][i] != 0) {
									PhoneSelected[j][i] = { 0 };
								}
							}
						}
						for (int i = 0; i < MOVIES; i++) {
							for (int j = 0; j < 2; j++) {
								if (MoviesSelected[j][i] != 0) {
									MoviesSelected[j][i] = { 0 };
								}
							}
						}
						for (int i = 0; i < AUTHORS; i++) {
							for (int j = 0; j < 7; j++) {
								if (BookSelected[j][i] != 0) {
									BookSelected[j][i] = { 0 };
								}
							}
						}
						for (int i = 0; i < VIDEOGAMES; i++) {
							if (VideogamesSelected[i] != 0) {
								VideogamesSelected[i] = { 0 };
							}
						}
						Menu();
					}
				}
			}
			else {
				CLEAR;
				cout << "Los Paralelepipedos Store: Shopping Cart" << endl << endl
					<< "Your cart is empty, add some items first!" << endl << endl;
				PAUSE;
				Menu();
			}
			break;

		case 7:
			Goodbye();
			exit(0);
			break;

		default:
			cout << "\nEnter a valid category: ";
		}

	} while (Retry == 'Y' || Retry == 'y');

	Goodbye();

	return 0;

}

void Menu() {

	CLEAR;

	cout << "Welcome to the 'Los Paralelepipedos++' store!" << endl
		<< "We sell a variety of televisions, phones, videogames, movies, and books!"
		<< endl << endl

		<< "Categories:" << endl
		<< "\t1) Televisions" << endl
		<< "\t2) Phones" << endl
		<< "\t3) Videogames " << endl
		<< "\t4) Movies" << endl
		<< "\t5) Books" << endl
		<< "\t6) Go to the cart!" << endl
		<< "\t7) Exit the application" << endl << endl

		<< "Select the category you would like to search: ";
}

void Goodbye() {

	CLEAR;
	cout << "Thanks for visiting Los Paralelepipedos Store!" << endl << endl
		<< "Come back soon!" << endl << endl
		<< "Application created by:"
		<< "\n\t1) Pablo Alexis Dominguez Grau"
		<< "\n\t2) Jose Luis Ojeda De Leon"
		<< endl << endl;

	PAUSE;
}

int Televisions(int tv_pass) {

	int tv = tv_pass;
	int TV_SamsungCost = 0, TV_VizioCost = 0, TV_LGCost = 0,
		TV_SharpCost = 0, TV_SonyCost = 0;
	short int TV_Selector;
	unsigned short int error = 0;

	TelevisionsMenu();

	do {

		cin >> TV_Selector;

		switch (TV_Selector) {

		case 1:
			tv += TV_Samsung(TV_SamsungCost);
			TelevisionsMenu();
			break;

		case 2:
			tv += TV_Vizio(TV_VizioCost);
			TelevisionsMenu();
			break;

		case 3:
			tv += TV_Sony(TV_SonyCost);
			TelevisionsMenu();
			break;

		case 4:
			tv += TV_LG(TV_LGCost);
			TelevisionsMenu();
			break;

		case 5:
			tv += TV_Sharp(TV_SharpCost);
			TelevisionsMenu();
			break;

		case 6:
			error++;
			break;

		default:
			cout << "\nEnter a valid TV Category: ";
		}
	} while (error == 0);

	return tv_pass += tv;
}

void TelevisionsMenu() {

	CLEAR;
	cout << "Los Paralelepipedos Store: TV's Category" << endl
		<< "We have a vast selection of premium TV brands!\n\n"
		<< "Television Brands:\n";

	for (int i = 0; i < TV; i++)
		cout << "\t" << i + 1 << ") " << TVBrands[i] << endl;

	cout << "\t6) " << INITIALIZE
		<< "\n\nSelect a television brand: ";
}

int TV_Samsung(int TV_SamsungCost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 0;

	CLEAR;
	cout << "Below are shown all our premium Samsung TV's in stock:\n\n";
	SHOW_TVS;
	INITIALIZE_TV;

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			TVCounter(quantity, value, TV_SamsungCost, selection, brand);
			StoreTVSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}
	} while (quit == 0);

	TVExitMessage(TV_SamsungCost, brand);
	return value;
}

int TV_Vizio(int TV_VizioCost) {

	int quantity = 0, value = 0;
	short int selection, quit = 0, brand = 1;

	CLEAR;
	cout << "Below are shown all our premium Vizio TV's in stock:\n\n";
	SHOW_TVS;
	INITIALIZE_TV;

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			TVCounter(quantity, value, TV_VizioCost, selection, brand);
			StoreTVSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	TVExitMessage(TV_VizioCost, brand);
	return value;
}

int TV_Sony(int TV_SonyCost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 2;

	CLEAR;
	cout << "Below are shown all our premium Sony TV's in stock:\n\n";
	SHOW_TVS;
	INITIALIZE_TV;

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			TVCounter(quantity, value, TV_SonyCost, selection, brand);
			StoreTVSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	TVExitMessage(TV_SonyCost, brand);
	return value;

}

int TV_LG(int TV_LGCost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 3;

	CLEAR;
	cout << "Below are shown all our premium LG TV's in stock:\n\n";
	SHOW_TVS;
	INITIALIZE_TV;

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			TVCounter(quantity, value, TV_LGCost, selection, brand);
			StoreTVSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	TVExitMessage(TV_LGCost, brand);
	return value;
}

int TV_Sharp(int TV_SharpCost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 4;

	CLEAR;
	cout << "Below are shown all our premium Sharp TV's in stock:\n\n";
	SHOW_TVS;
	INITIALIZE_TV;

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			TVCounter(quantity, value, TV_SharpCost, selection, brand);
			StoreTVSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	TVExitMessage(TV_SharpCost, brand);
	return value;
}

void TVCounter(int &quantity, int &value, int &TVCost, int selection, short int brand) {

	short int selected = selection - 1;

	cout << "\nHow many TVs of this type you would like to buy?: ";
	cin >> quantity;

	while (quantity <= 0) {
		cout << INVALID_QUANTITY;
		cin >> quantity;
	}

	TVCost += (quantity*TVPrices[brand][selected]);
	value = TVCost;

	cout << ITEM_ADDED
		<< "If you would like to buy another " << TVBrands[brand] << " TV, please select it now: ";
}

void StoreTVSelected(short int selection, int quantity, short int brand) {

	int selected = selection - 1;
	TVSelected[brand][selected] += quantity;

}

void TVExitMessage(int TVCost, short int brand) {

	if (TVCost == 0) {
		cout << "\n\nYou can visit the" << TVBrands[brand] << " TV category again anytime you want!\n\n";
	}
	else {
		cout << "\n\nThanks for adding a TV to your cart! Keep shopping!" << endl << endl;
		PAUSE;
	}
}

int Smartphones(int phone_pass) {

	int phone = phone_pass;
	int SamsungPhone_Cost = 0, HTCPhone_Cost = 0, ApplePhone_Cost = 0,
		LGPhone_Cost = 0, SonyPhone_Cost = 0;
	short int PhoneSelector;
	unsigned short int error = 0;

	PhoneMenu();

	do {

		cin >> PhoneSelector;

		switch (PhoneSelector) {

		case 1:
			phone += Apple_Phone(ApplePhone_Cost);
			PhoneMenu();
			break;

		case 2:
			phone += Samsung_Phone(SamsungPhone_Cost);
			PhoneMenu();
			break;

		case 3:
			phone += HTC_Phone(HTCPhone_Cost);
			PhoneMenu();
			break;

		case 4:
			phone += LG_Phone(LGPhone_Cost);
			PhoneMenu();
			break;

		case 5:
			phone += Sony_Phone(SonyPhone_Cost);
			PhoneMenu();
			break;

		case 6:
			error++;
			break;

		default:
			cout << "\nEnter a valid Smartphone Category: ";
		}
	} while (error == 0);

	return phone_pass += phone;
}

void PhoneMenu() {

	// Clear the screen
	CLEAR;

	cout << "Los Paralelepipedos Store: Smartphones' Category" << endl
		<< "We have a vast selection of premium smartphone brands." << endl << endl
		<< "Smartphone Brands: " << endl;

	for (int i = 0; i < PHONES; i++)
		cout << "\t" << i + 1 << ") " << PhoneBrands[i] << endl;

	cout << "\t6) " << INITIALIZE << endl << endl
		<< "Select a smartphone brand: ";

}

int Apple_Phone(int ApplePhone_Cost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 0;

	CLEAR;
	cout << "Apple\n\n"
		<< "All Apple iPhones come with astonishing 12MP cameras and a vibrant Retina HD Display.\n"
		<< "Below are shown all our premium Apple smartphones' in stock: "
		<< endl << endl;

	SHOW_PHONES;
	INITIALIZE_PHONE(6);

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			PhoneCounter(quantity, value, ApplePhone_Cost, selection, brand);
			StorePhoneSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	PhoneExitMessage(ApplePhone_Cost, brand);
	return value;
}

int Samsung_Phone(int SamsungPhone_Cost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 1;

	CLEAR;
	cout << "Samsung\n\n"
		<< "Samsung smartphones have on board the advanced Exynos 7/8 Octa Core 7420/8890 Processors and the best\nQHD displays in the market."
		<< "With up to 4GB of RAM and up to 16MP crystal clear cameras, and up to 2.2GHz processing power, these \nmobile devices are among the best."
		<< "Below are shown all our premium Samsung smartphones' in stock: "
		<< endl << endl;

	SHOW_PHONES;
	INITIALIZE_PHONE(6);

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			PhoneCounter(quantity, value, SamsungPhone_Cost, selection, brand);
			StorePhoneSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	PhoneExitMessage(SamsungPhone_Cost, brand);
	return value;
}

int HTC_Phone(int HTCPhone_Cost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 2;

	CLEAR;
	cout << "HTC\n\n"
		<< "HTC Android phones are equipped with Full and QHD Displays, from 3GB to 4GB of RAM, and 12MP to 16MP outstanding cameras."
		<< "Below are shown all our premium HTC smartphones' in stock: "
		<< endl << endl;

	SHOW_PHONES;
	INITIALIZE_PHONE(5);

	do {

		cin >> selection;

		if (selection > 0 && selection < 5) {
			PhoneCounter(quantity, value, HTCPhone_Cost, selection, brand);
			StorePhoneSelected(selection, quantity, brand);
		}
		else if (selection == 5) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	PhoneExitMessage(HTCPhone_Cost, brand);

	return value;
}

int LG_Phone(int LGPhone_Cost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 3;

	CLEAR;
	cout << "LG\n\n"
		<< "The high-quality LG smartphones keep inside their own shell the poweful Hexa Core Snapdragon 808 or the Quad Core \nSnapdragon 801 Processor."
		<< "All these LGs sport cameras ranging from the average 8MP to the crisp and vibrant 16MP, with HD\nandQHD displays that will "
		<< "never fail to deliver the best colors a screen could ever provide, and with up to 4GB of RAM there's nothing else to say.\n"
		<< "Below are shown all our premium LG smartphones' in stock: "
		<< endl << endl;

	SHOW_PHONES;
	INITIALIZE_PHONE(6);

	do {

		cin >> selection;

		if (selection > 0 && selection < 6) {
			PhoneCounter(quantity, value, LGPhone_Cost, selection, brand);
			StorePhoneSelected(selection, quantity, brand);
		}
		else if (selection == 6) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	PhoneExitMessage(LGPhone_Cost, brand);

	return value;
}

int Sony_Phone(int SonyPhone_Cost) {

	int quantity = 0, value = 0;
	short int selection = 0, quit = 0, brand = 4;

	CLEAR;
	cout << "Sony\n\n"
		<< "Sony's flagship, the Xperia, has its many versions.  From HD to Triluminos Displays, 3GB of RAM, some of the\n"
		<< "latest mobile processors, like the Quad Core Snapdragon 800 and 820, and astonishing 23MP cameras, the flagship\n"
		<< "may be the best for tour daily use."
		<< "Below are shown all our premium Sony smartphones' in stock: "
		<< endl << endl;

	SHOW_PHONES;
	INITIALIZE_PHONE(5);

	do {

		cin >> selection;

		if (selection > 0 && selection < 5) {
			PhoneCounter(quantity, value, SonyPhone_Cost, selection, brand);
			StorePhoneSelected(selection, quantity, brand);
		}
		else if (selection == 5) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	PhoneExitMessage(SonyPhone_Cost, brand);

	return value;
}

void PhoneExitMessage(int phonecost, short int brand) {

	if (phonecost == 0) {
		cout << "\n\nYou can visit the " << PhoneBrands[brand] << " Smartphone category again anytime you want!" << endl;
	}
	else {
		cout << "\n\nThanks for adding a smartphone to your cart! Keep shopping!" << endl;
		PAUSE;
	}
}

void PhoneCounter(int &quantity, int &value, int &PhoneCost, int selection, short int brand) {

	short int selected = selection - 1;
	cout << "\nHow many smartphones of this type you would like to buy?: ";
	cin >> quantity;

	while (quantity <= 0) {
		cout << INVALID_QUANTITY;
		cin >> quantity;
	}

	PhoneCost += (quantity*PhonePrices[brand][selected]);
	value = PhoneCost;

	cout << ITEM_ADDED
		<< "If you would like to buy another " << PhoneBrands[brand] << " smartphone, please select it now: ";
}

void StorePhoneSelected(short int selection, int quantity, short int brand) {

	int selected = selection - 1;
	PhoneSelected[brand][selected] += quantity;

}

int Videogames(int Videogames_Cost, int game_pass) {

	int quantity = 0, games = game_pass;
	short int selection = 0, quit = 0;

	CLEAR;
	cout << "Los Paralelepipedos Store: Videogames Section\n\n"
		<< "Videogames are the essential part of gamers.  Enjoy our low prices for the highest rated games!"
		<< "\nBelow are shown all the great videogames that we have in stock:\n\n";

	for (int i = 0; i < VIDEOGAMES; i++) {

		if (i < 9) {
			cout << "\t" << i + 1 << ") " << VideogamesNames[i]
				<< setw(5) << "$" << VideogamesPrices[i] << endl;
		}
		else {
			cout << "\t" << i + 1 << ") " << VideogamesNames[i]
				<< setw(4) << "$" << VideogamesPrices[i] << endl;
		}
	}

	cout << "\t31) " << INITIALIZE << endl << endl
		<< "Select the videogame you would like to buy: ";

	do {

		cin >> selection;

		if (selection > 0 && selection < 31) {
			VideogameCounter(quantity, games, Videogames_Cost, selection);
			StoreVideogameSelected(selection, quantity);
		}
		else if (selection == 31) {
			quit++;
		}
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);


	if (Videogames_Cost == 0) {
		cout << "\n\nYou can visit the videogames category again anytime you want! " << endl << endl;
	}
	else {
		cout << "\n\nThanks for adding a videogame(s) to your cart! Keep shopping!" << endl << endl;
		PAUSE;
	}
	return game_pass += games;
}

void VideogameCounter(int &quantity, int &games, int &Videogames_Cost, short int selection) {

	short int selected = selection - 1;

	cout << "\nHow many copies of this videogame you would like to buy? ";
	cin >> quantity;

	while (quantity <= 0) {
		cout << INVALID_QUANTITY;
		cin >> quantity;
	}

	Videogames_Cost += (quantity*VideogamesPrices[selected]);
	games = Videogames_Cost;

	cout << ITEM_ADDED
		<< "If you would like to buy another videogame, please select it now: ";

}

void StoreVideogameSelected(short int selection, int quantity) {

	int selected = selection - 1;
	VideogamesSelected[selected] += quantity;

}

double Movies(double Movies_Cost, double movies_pass) {

	/// Declaration of variables.
	double movies = movies_pass;
	int quantity = 0;
	short int selection = 0, format = 0, quit = 0;

	// Clear the screen.
	CLEAR;

	// Display Movie Section message.
	cout << "Los Paralelepipedos Store: Movies Category\n\n"
		<< "Below are shown all the great movies (DVD/Blu-ray) that we have in stock:\n"
		<< "Note: Blu-ray movies have a 25% extra cost.\n\n";

	// Display the movies' names and their respect DVD and BluRay costs.
	// These names and prices are stored in public arrays for easy access.
	cout << setprecision(2) << fixed;

	for (int i = 0; i < MOVIES; i++) {
		if (i < 9) {
			cout << "\t " << i + 1 << ") " << MoviesNames[i]
				<< setw(5) << "$" << MoviesPriceDVD_BLURAY[0][i] << " / $"
				<< MoviesPriceDVD_BLURAY[1][i] << endl;
		}
		else {
			cout << "\t" << i + 1 << ") " << MoviesNames[i]
				<< setw(4) << "$" << MoviesPriceDVD_BLURAY[0][i] << " / $"
				<< MoviesPriceDVD_BLURAY[1][i] << endl;
		}
	}

	cout << "\t26) " << INITIALIZE
		<< "\n\nSelect the movies you would like to buy: ";

	do {

		// The program reads the input (or selection) the user enters.
		cin >> selection;

		// Input Validation.
		if (selection > 0 && selection < 26) {

			// Ask for CD format and allow user input.
			cout << "\nWhich format you prefer?" << endl
				<< "\t1) DVD" << endl
				<< "\t2) Blu-ray" << endl
				<< "\tSelect the format: ";
			cin >> format;

			// Input Validation.
			while (format < 1 || format > 2) {
				cout << "\nEnter a valid format: ";
				cin >> format;
			}

			// Call the required functions to perform the calculations.
			MovieCounter(quantity, movies, Movies_Cost, selection, format);
			StoreMovieSelected(selection, quantity, format);
		}

		// Exit the loop.
		else if (selection == 26) {
			quit++;
		}

		// Display Invalid Input message.
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);

	// Display exit message.
	if (Movies_Cost == 0) {
		cout << "\n\nYou can visit the Movie category again anytime you want! " << endl << endl;
	}
	else {
		cout << "\n\nThanks for adding a movie(s) to your cart! Keep shopping!" << endl << endl;
		PAUSE;
	}

	// Return the total value stored.
	return movies_pass += movies;
}

void MovieCounter(int &quantity, double &movies, double &Movies_Cost, short int selection, short int format) {

	short int selected = selection - 1;

	cout << "\nHow many copies of this movie you would like to buy? ";
	cin >> quantity;

	while (quantity <= 0) {
		cout << INVALID_SELECTION;
		cin >> quantity;
	}

	if (format == 1) {
		Movies_Cost += (quantity*MoviesPriceDVD_BLURAY[0][selected]);
	}
	else {
		Movies_Cost += (quantity*MoviesPriceDVD_BLURAY[1][selected]);
	}
	movies = Movies_Cost;

	cout << ITEM_ADDED
		<< "If you would like to buy another movie, please select it now: ";
}

void StoreMovieSelected(short int selection, int quantity, short int format) {

	const short int DVD = 0, BLURAY = 1;

	int selected = selection - 1;
	if (format == 1) {
		MoviesSelected[DVD][selected] += quantity;
	}
	else {
		MoviesSelected[BLURAY][selected] += quantity;
	}
}


int Books(int Books_Cost, int book_pass) {

	int book = book_pass, counter = 0;
	short int selection = 0, quit = 0, author;
	int quantity = 0;

	CLEAR;
	cout << "Los Paralelepipedos Store: Books Category\n"
		<< "Below are shown all the amazing books that we have in stock:\n\n";


	for (int i = 0; i < AUTHORS; i++) {
		cout << "By " << AuthorsNames[i] << ":";
		for (int j = 0; j < 7; j++) {
			if (BooksPrices[i][j] != 0 && counter < 9) {
				counter++;
				cout << "\n\t" << counter << ") " << BooksNames[i][j]
					<< setw(5) << "$" << BooksPrices[i][j];
			}
			else if (BooksPrices[i][j] != 0 && counter >= 9) {
				counter++;
				cout << "\n\t" << counter << ") " << BooksNames[i][j]
					<< setw(4) << "$" << BooksPrices[i][j];
			}
		}
		cout << endl << endl;
	}

	cout << "\t21) " << INITIALIZE
		<< "\n\nSelect the book you would like to buy: ";

	do {

		cin >> selection;

		if (selection > 0 && selection < 21) {

			if (selection <= 4) {
				author = 0;
			}
			else if (selection <= 11) {
				author = 1;
			}
			else if (selection <= 15) {
				author = 2;
			}
			else if (selection == 16) {
				author = 3;
			}
			else if (selection == 17) {
				author = 4;
			}
			else if (selection == 18) {
				author = 5;
			}
			else if (selection == 19) {
				author = 6;
			}
			else if (selection == 20) {
				author = 7;
			}
			BookCounter(quantity, book, Books_Cost, selection, author);
			StoreBookSelected(selection, quantity, author);
		}

		// Exit the loop
		else if (selection == 21) {
			quit++;
		}

		// Display Invalid Input message.
		else {
			cout << INVALID_SELECTION;
		}

	} while (quit == 0);


	if (Books_Cost == 0) {
		cout << "\n\nYou can visit the Book category again anytime you want! " << endl << endl;
	}
	else {
		cout << "\n\nThanks for adding a book(s) to your cart! Keep shopping!" << endl << endl;
		PAUSE;
	}
	return book_pass += book;
}

void BookCounter(int &quantity, int &book, int &Books_Cost, short int selection, short int author) {

	short int selected;

	if (selection <= 4) {
		selected = selection - 1;
	}
	else if (selection <= 11) {
		selected = selection - 5;
	}
	else if (selection <= 15) {
		selected = selection - 12;
	}
	else {
		selected = 0;
	}

	cout << "\nHow many copies of this book you would like to buy?: ";
	cin >> quantity;

	while (quantity <= 0) {
		cout << INVALID_QUANTITY;
		cin >> quantity;
	}

	Books_Cost += quantity * BooksPrices[author][selected];
	book = Books_Cost;

	cout << ITEM_ADDED
		<< "If you would like to buy another book, please select it now: ";
}

void StoreBookSelected(short int selection, int quantity, short int author) {

	int selected;

	if (selection <= 4) {
		selected = selection - 1;
	}
	else if (selection <= 11) {
		selected = selection - 5;
	}
	else if (selection <= 15) {
		selected = selection - 12;
	}
	else {
		selected = 0;
	}

	BookSelected[author][selected] += quantity;
}

double Cart(int tv, int phone, int game,
	double movie, int book, bool Back) {

	CartOK = 1;

	char StoreCard;
	double Municipal = 0, State = 0, Total = 0, Tax = 0,
		GreatTotal = 0, Savings = 0, TotalPaid = 0,
		PercentageDiscount;

	short int PaymentType, error = 0;
	const short int CARD_DISCOUNT = 5;
	const double STATE_TAX = 0.105, MUNICIPAL_TAX = 0.01;

	CLEAR;
	RemovalQuestion(tv, phone, game, movie, book);
	CLEAR;

	cout << "Los Paralelepipedos Store: Shopping Cart" << endl << endl;

	if (tv + phone + game + movie + book != 0) {

		cout << "\nDo you have the store rewards card? (Y/N): ";
		cin >> StoreCard;

		if (StoreCard == 'Y' || StoreCard == 'y') {
			TypeOfPayments();
			Total = tv + phone + game + book + movie;
			Municipal = Total*MUNICIPAL_TAX;
			State = Total*STATE_TAX;
			Tax = (MUNICIPAL_TAX + STATE_TAX)*Total;

			do {
				cin >> PaymentType;

				switch (PaymentType) {
				case 1:
					Receipt(tv, phone, game, movie, book);
					PercentageDiscount = 0.25;
					Savings = (Total*PercentageDiscount) + CARD_DISCOUNT;
					GreatTotal = Total + Tax;
					TotalPaid = GreatTotal - Savings;
					Outputs(Total, Municipal, State, Tax, GreatTotal, TotalPaid, Savings);
					error++;
					break;

				case 2:
				case 3:
					Receipt(tv, phone, game, movie, book);
					PercentageDiscount = 0.15;
					Savings = (Total*PercentageDiscount) + CARD_DISCOUNT;
					GreatTotal = Total + Tax;
					TotalPaid = GreatTotal - Savings;
					Outputs(Total, Municipal, State, Tax, GreatTotal, TotalPaid, Savings);
					error++;
					break;

				case 4:
					Back = 1;
					error++;
					break;

				default:
					cout << "\nEnter a valid type of payment: ";
				}
			} while (error == 0);
		}
		else {
			TypeOfPayments();
			Total = tv + phone + game + book + movie;
			Municipal = Total*MUNICIPAL_TAX;
			State = Total*STATE_TAX;
			Tax = (MUNICIPAL_TAX + STATE_TAX)*Total;

			do {
				cin >> PaymentType;

				switch (PaymentType) {
				case 1:
				case 2:
				case 3:
					Receipt(tv, phone, game, movie, book);
					Savings = 0;
					GreatTotal = (Total + Tax);
					TotalPaid = GreatTotal;
					Outputs(Total, Municipal, State, Tax, GreatTotal, TotalPaid, Savings);
					error++;
					break;

				case 4:
					Back = 1;
					error++;
					break;

				default:
					cout << "\nEnter a valid type of payment: ";
				}
			} while (error == 0);
		}

	}
	else {

		cout << "You have removed all the items from your shopping cart.\n"
			<< "You will be redirected to the main menu!";
		Back = 1;
	}

	cout << endl << endl;
	PAUSE;
	return Back;
}

void Receipt(int tv, int phone, int game, double movie, int book) {

	double BluRayCost = 0;

	CLEAR;
	cout << setprecision(2) << fixed;

	cout << "Los Paralelepipedos Store: Purchase Receipt" << endl << endl
		<< "Items Bought:" << endl << endl;

	if (tv > 0) {
		cout << "TVs:" << setw(9) << "$" << tv << endl;
		for (int i = 0; i < TV; i++) {
			for (int j = 0; j < TV; j++) {
				if (TVSelected[i][j] > 0) {
					cout << "\t" << TVNames[i][j] << setw(4)
						<< "Quantity: " << TVSelected[i][j]
						<< setw(8) << "\tPrice: $" << TVPrices[i][j]
						<< endl;
				}
			}
		}
		cout << endl;
	}

	if (phone > 0) {
		cout << "Phones:" << setw(6) << "$" << phone << endl;
		for (int i = 0; i < PHONES; i++) {
			for (int j = 0; j < PHONES; j++) {
				if (PhoneSelected[i][j] > 0) {
					cout << "\t" << PhonesNames[i][j] << setw(4)
						<< "Quantity: " << PhoneSelected[i][j]
						<< setw(8) << "\tPrice: $" << PhonePrices[i][j]
						<< endl;
				}
			}
		}
		cout << endl;
	}

	if (game > 0) {
		cout << "Videogames:" << setw(2) << "$" << game << endl;
		for (int i = 0; i < VIDEOGAMES; i++) {
			if (VideogamesSelected[i] > 0) {
				cout << "\t" << VideogamesNames[i] << setw(4)
					<< "Quantity: " << VideogamesSelected[i]
					<< setw(8) << "\tPrice: $" << VideogamesPrices[i]
					<< endl;
			}
		}
		cout << endl;
	}

	if (movie > 0) {
		cout << "Movies:" << setw(7) << "$" << movie << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < MOVIES; j++) {
				if (MoviesSelected[i][j] > 0) {
					cout << "\t" << MoviesNames[j] << setw(4)
						<< "Quantity: " << MoviesSelected[i][j]
						<< setw(8) << "\tPrice: $" << MoviesPriceDVD_BLURAY[i][j]
						<< endl;
				}
			}
		}
	}

	if (book > 0) {
		cout << "Books:" << setw(7) << "$" << book << endl;
		for (int i = 0; i < AUTHORS; i++) {
			for (int j = 0; j < 7; j++) {
				if (BookSelected[i][j] > 0) {
					cout << "\t" << BooksNames[i][j] << setw(4)
						<< "Quantity: " << BookSelected[i][j]
						<< setw(8) << "\tPrice: $" << BooksPrices[i][j]
						<< endl;
				}
			}
		}
		cout << endl;
	}

	
}

void TypeOfPayments() {

	cout << "\n\nTypes of payments: " << endl
		<< "\t1) Store Credit Card" << endl
		<< "\t2) Debit Card" << endl
		<< "\t3) Cash" << endl
		<< "\t4) Cancel the order and go back to the main menu" << endl << endl
		<< "Select your type of payment: ";
}

void Outputs(double Total, double Municipal, double State, double Tax, double GreatTotal, double TotalPaid, double Savings) {

	if (Savings > 0) {
		cout << "\n\nTotal:             $" << Total << endl
			<< "Municipal Tax:     $" << Municipal << endl
			<< "State Tax:         $" << State << endl
			<< "Sales Tax:         $" << Tax << endl << endl
			<< "Great Total:       $" << GreatTotal << endl
			<< "Total Paid:        $" << TotalPaid << endl
			<< "Today's Savings:   $" << Savings;
	}
	else {
		cout << "\n\nTotal:             $" << Total << endl
			<< "Municipal Tax:     $" << Municipal << endl
			<< "State Tax:         $" << State << endl
			<< "Sales Tax:         $" << Tax << endl << endl
			<< "Great Total:       $" << GreatTotal << endl
			<< "Total Paid:        $" << TotalPaid << endl
			<< "Today's Savings:   $" << Savings << endl << endl
			<< "In order to have amazing savings, remember to take your Store Rewards Card next time!";
	}
}

void SectionTypes(string SectionType[], short int &Section) {
	
	CLEAR;
		cout << "From which of the following sections you would like to remove an item?\n";
		
		for (int i = 0; i < 5; i++)
			cout << "\t" << i + 1 << ") " << SectionType[i] << endl;
		
		cout << "\nMake your selection: ";
		cin >> Section;

		while (Section < 0 || Section > 5) {
			cout << INVALID_SELECTION;
			cin >> Section;
		}
}

void TypeValidation(int type, int x, int Section, string SectionType[]) {

if (type == 0 && Section == x) {
			cout << "\n\nYou have not selected any " << SectionType[x] << "."
				<< INVALID_SELECTION;
		}

}

void ShowRemovableItems(int &tv, int &phone, int &game, double &movie, int &book) {

	int Array[5][30] = { {0} };
	string SectionType[5] = { "Televisions", "Smartphones", "Videogames", "Movies", "Books" };
	short int Section = 0;
	short int CHECK_ID = 0, CHECK_ITEM = 0;
	int ItemToRemove, QuantityToRemove;
	bool OK = true, TypeOK = false;

	do {
		SectionTypes(SectionType, Section);
		if (tv == 0 && Section == 1) {
			while (Section == 1) {
				cout << "\n\nYou have not selected any " << SectionType[0] << "."
					<< INVALID_SELECTION;
				cin >> Section;
			}
		}
		else if (phone == 0 && Section == 2) {
			while (Section == 2) {
				cout << "\n\nYou have not selected any " << SectionType[1] << "."
					<< INVALID_SELECTION;
				cin >> Section;
			}
		}
		else if (game == 0 && Section == 3) {
			while (Section == 3) {
				cout << "\n\nYou have not selected any " << SectionType[2] << "."
					<< INVALID_SELECTION;
				cin >> Section;
			}
		}
		else if (movie == 0 && Section == 4) {
			while (Section == 4) {
				cout << "\n\nYou have not selected any " << SectionType[3] << "."
					<< INVALID_SELECTION;
				cin >> Section;
			}
		}
		else if (book == 0 && Section == 5) {
			while (Section == 5) {
				cout << "\n\nYou have not selected any " << SectionType[0] << "."
					<< INVALID_SELECTION;
				cin >> Section;
			}
		}

		switch (Section) {
		case 1:

			cout << "Items available for removal:\n\n";
			if (tv > 0) {
				cout << "TVs:" << setw(9) << "$" << tv << endl;
				for (int i = 0; i < TV; i++) {
					for (int j = 0; j < TV; j++) {
						CHECK_ID++;
						if (TVSelected[i][j] > 0) {
							cout << "ID: " << ITEMS_ID[0][CHECK_ID - 1] << "    " << TVNames[i][j]
								<< setw(4) << "Quantity: " << TVSelected[i][j]
								<< setw(8) << "\tPrice: $" << TVPrices[i][j]
								<< endl;
						}
					}
				}
				cout << endl;
			}


		}
	
		cout << "Items available for removal:\n\n";
		if (tv > 0) {
			cout << "TVs:" << setw(9) << "$" << tv << endl;
			for (int i = 0; i < TV; i++) {
				for (int j = 0; j < TV; j++) {
					CHECK_ID++;
					if (TVSelected[i][j] > 0) {
						cout << "ID: " << ITEMS_ID[0][CHECK_ID - 1] << "    " << TVNames[i][j]
							<< setw(4) << "Quantity: " << TVSelected[i][j]
							<< setw(8) << "\tPrice: $" << TVPrices[i][j]
							<< endl;
					}
				}
			}
			cout << endl;
		}

		CHECK_ID = 0;
		if (phone > 0) {
			cout << "Phones:" << setw(6) << "$" << phone << endl;
			for (int i = 0; i < PHONES; i++) {
				for (int j = 0; j < PHONES; j++) {
					CHECK_ID++;
					if (PhoneSelected[i][j] > 0) {
						cout << "ID: " << ITEMS_ID[1][CHECK_ID - 1] << "    " << PhonesNames[i][j]
							<< setw(4) << "Quantity: " << PhoneSelected[i][j]
							<< setw(8) << "\tPrice: $" << PhonePrices[i][j]
							<< endl;
					}
				}
			}
			cout << endl;
		}

		CHECK_ID = 0;
		if (game > 0) {
			cout << "Videogames:" << setw(2) << "$" << game << endl;
			for (int i = 0; i < VIDEOGAMES; i++) {
				CHECK_ID++;
				if (VideogamesSelected[i] > 0) {
					cout << "ID: " << ITEMS_ID[2][CHECK_ID - 1] << "    " << VideogamesNames[i]
						<< setw(4) << "Quantity: " << VideogamesSelected[i]
						<< setw(8) << "\tPrice: $" << VideogamesPrices[i]
						<< endl;
				}
			}
			cout << endl;
		}

		CHECK_ID = 0;
		if (movie > 0) {
			cout << "Movies:" << setw(7) << "$" << movie << endl;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < MOVIES; j++) {
					CHECK_ID++;
					if (MoviesSelected[i][j] > 0) {
						cout << "ID: " << ITEMS_ID[3][CHECK_ID - 1] << "    " << MoviesNames[i]
							<< setw(4) << "Quantity: " << MoviesSelected[i][j]
							<< setw(8) << "\tPrice: $" << MoviesPriceDVD_BLURAY[i][j]
							<< endl;
					}
				}
			}
			cout << endl;
		}

		CHECK_ID = 0;
		if (book > 0) {
			cout << "Books:" << setw(7) << "$" << book << endl;
			for (int i = 0; i < AUTHORS; i++) {
				for (int j = 0; j < 7; j++) {
					CHECK_ID++;
					if (BookSelected[i][j] > 0) {
						cout << "ID: " << ITEMS_ID[4][CHECK_ID - 1] << "    " << BooksNames[i][j]
							<< setw(4) << "Quantity: " << BookSelected[i][j]
							<< setw(8) << "\tPrice: $" << BooksPrices[i][j]
							<< endl;
					}
				}
			}
			cout << endl;
		}
		cout << "\nYou can enter 0 (zero) if you don't want to delete an item.\n"
			<< "Otherwise, enter the item ID number in order to delete it from your purchase: ";
		cin >> ItemToRemove;

		while (ItemToRemove < 0 || ItemToRemove > MAX_BOOK_ID) {
			cout << "\nInvalid ID number. Enter a value between 0 and 148: ";
			cin >> ItemToRemove;
		}


		if (ItemToRemove <= MAX_TV_ID) {
			if (ItemToRemove <= 5) {
				for (int i = 0; i < TV; i++) {
					if (TVSelected[0][i] > 0) {
						if (ItemToRemove == i) {
							ItemRemoval(ItemToRemove, QuantityToRemove, tv, phone, game, movie, book);
						}
					}
				}
			}
			else if (ItemToRemove <= 10) {
				for (int i = 0; i < TV; i++) {
					if (TVSelected[1][i] > 0) {
						if (ItemToRemove - 5 == i) {
							ItemRemoval(ItemToRemove, QuantityToRemove, tv, phone, game, movie, book);
						}
					}
				}
			}
		}

		/*
		int index[5][30] = { {0} };
		int search = 0, position = -1;
		bool found = false;
		*/
		if (ItemToRemove == 0) {
			CLEAR;
			cout << "You successfully canceled the item removal.\n"
				<< "You will be redirected to the Cart Section!\n\n";
			PAUSE;
		}
		else {
			if (ItemToRemove != 0) {

				cout << "\n\nSpecify the item's quantity you want to remove: ";
				cin >> QuantityToRemove;

				while (QuantityToRemove < 0) {
					cout << INVALID_QUANTITY;
					cin >> QuantityToRemove;
				}

				ItemRemoval(ItemToRemove, QuantityToRemove, tv, phone, game, movie, book);

			}
			else {
				OK = false;
				CLEAR;
				cout << "You successfully canceled the item removal.\n"
					<< "You will be redirected to the Cart Section!\n\n";
				PAUSE;
			}
			ItemRemoval(ItemToRemove, QuantityToRemove, tv, phone, game, movie, book);
		}
	} while (OK == true);
}
	

		/*
		else if (ItemToRemove <= MAX_TV_ID) {
			//	while (search < TV) {
			for (int i = 0; i < TV; i++) {
				for (int j = 0; j < TV; j++) {
					CHECK_ITEM++;
					if (TVSelected[i][j] > 0) {
						index[0][CHECK_ITEM - 1] = 1;
						/*switch (search) {
						case 0:
							position = search;
							break;
						case 1:
							position = search + 5;
							break;
						case 2:
							position = search + 10;
							break;
						case 3:
							position = search + 15;
							break;
						case 4:
							position = search + 20;
						}
						index[position] = 1;
						
					}
				}
			}
			//search++;
		//}
//		ResetSearchPosition(search, position);
		}


		else if (ItemToRemove <= MAX_PHONE_ID) {
			CHECK_ITEM = 0;
			for (int i = 0; i < PHONES; i++) {
				for (int j = 0; j < PHONES; j++) {
					CHECK_ITEM++;
					if (PhoneSelected[i][j] > 0) {
						//position = PhoneSelected[i][CHECK_ITEM - 1];
						index[1][CHECK_ITEM - 1] = 1;
					}
				}
			}
			//	ResetSearchPosition(search, position);
		}
		else if (ItemToRemove <= MAX_VIDEOGAME_ID) {
			CHECK_ITEM = 0;
			//while (search < VIDEOGAMES) {
			for (int i = 0; i < VIDEOGAMES; i++) {
				CHECK_ITEM++;
				if (VideogamesSelected[i] > 0) {
					//	position = VideogamesSelected[search];
					index[2][CHECK_ITEM - 1] = 1;
				}
			}
			//	search++;
		//	}
			//ResetSearchPosition(search, position);
		}
		else if (ItemToRemove <= MAX_MOVIE_ID) {
			CHECK_ITEM = 0;
			//	while (search < 2) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < MOVIES; j++) {
					CHECK_ITEM++;
					if (MoviesSelected[i][j] > 0) {
						//position = PhoneSelected[search][i];
						index[3][CHECK_ITEM - 1] = 1;
					}
				}
				//	}
					//search++;
			}
			//ResetSearchPosition(search, position);
		}

		/*
	//	for (int i = 0; i < TOTAL_ITEMS && !found; i++) {
		//	if (index[i] - 1 == 0 && ItemToRemove == i + 1) {
			//	found = true;
				//OK = false;
		//	}
		//	if (index[i] != 0 && i + 1 == ItemToRemove) {
		//		found = true;
		//		OK = false;
		//	}

		//}
		
		if (ItemToRemove <= MAX_TV_ID) {
			for (int i = 0; i < MAX_TV_ID, found == false; i++) {
				if (index[0][i] == 1 && ItemToRemove == i + 1) {
						found = true;
				}
			}
		}

		if (found == true) {

			if (ItemToRemove != 0) {

				cout << "\n\nSpecify the item's quantity you want to remove: ";
				cin >> QuantityToRemove;

				while (QuantityToRemove < 0) {
					cout << INVALID_QUANTITY;
					cin >> QuantityToRemove;
				}

				ItemRemoval(ItemToRemove, QuantityToRemove, tv, phone, game, movie, book);

			}
			else {
				OK = false;
				CLEAR;
				cout << "You successfully canceled the item removal.\n"
					<< "You will be redirected to the Cart Section!\n\n";
				PAUSE;
			}
		}
		else {
			CLEAR;
			cout << "The item ID #" << ItemToRemove << " entered does not match with any of the items in your cart.\n"
				<< "Please enter a valid ID number.\n\n";
			PAUSE;
		}
	} while (OK == true);
	
} 
*/



void ResetSearchPosition(int &search, int &position) {

	if (search != 0 || position != -1) {
		search = 0;
		position = -1;
	}
}

void ShowItems(int tv, int phone, int game, double movie, int book) {

	if (tv > 0) {
		cout << "TVs:" << setw(9) << "$" << tv << endl;
		for (int i = 0; i < TV; i++) {
			for (int j = 0; j < TV; j++) {
				if (TVSelected[j][i] > 0) {
					cout << "\t" << TVNames[j][i] << setw(4)
						<< "Quantity: " << TVSelected[j][i]
						<< setw(8) << "\tPrice: $" << TVPrices[j][i]
						<< endl;
				}
			}
		}
		cout << endl;
	}

	if (phone > 0) {
		cout << "Phones:" << setw(6) << "$" << phone << endl;
		for (int i = 0; i < PHONES; i++) {
			for (int j = 0; j < PHONES; j++) {
				if (PhoneSelected[j][i] > 0) {
					cout << "\t" << PhonesNames[j][i] << setw(4)
						<< "Quantity: " << PhoneSelected[j][i]
						<< setw(8) << "\tPrice: $" << PhonePrices[j][i]
						<< endl;
				}
			}
		}
		cout << endl;
	}

	if (game > 0) {
		cout << "Videogames:" << setw(2) << "$" << game << endl;
		for (int i = 0; i < VIDEOGAMES; i++) {
			if (VideogamesSelected[i] > 0) {
				cout << "\t" << VideogamesNames[i] << setw(4)
					<< "Quantity: " << VideogamesSelected[i]
					<< setw(8) << "\tPrice: $" << VideogamesPrices[i]
					<< endl;
			}
		}
		cout << endl;
	}
	
	if (movie > 0) {
		cout << "Movies:" << setw(7) << "$" << movie << endl;
		for (int i = 0; i < MOVIES; i++) {
			for (int j = 0; j < 2; j++) {
				if (MoviesSelected[j][i] > 0) {
					cout << "\t" << MoviesNames[i] << setw(4)
						<< "Quantity: " << MoviesSelected[j][i]
						<< setw(8) << "\tPrice: $" << MoviesPriceDVD_BLURAY[j][i]
						<< endl;
				}
			}
		}
		cout << endl;
	}

	if (book > 0) {
		cout << "Books:" << setw(7) << "$" << book << endl;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < AUTHORS; j++) {
				if (BookSelected[j][i] > 0) {
					cout << "\t" << BooksNames[j][i] << setw(4)
						<< "Quantity: " << BookSelected[j][i]
						<< setw(8) << "\tPrice: $" << BooksPrices[j][i]
						<< endl;
				}
			}
		}
		cout << endl;
	}
}

void RemovalQuestion(int &tv, int &phone, int &game, double &movie, int &book) {

	char remove = 'y';

	do {
		CLEAR;
		if (tv + phone + game + movie + book != 0) {
			cout << "Los Paralelepipedos++ Store: Cart\n\n";


			cout << "This is your receipt:\n\n";

			ShowItems(tv, phone, game, movie, book);

			cout << "Do you want to remove an item before your purchase? (Y/N): ";
			cin >> remove;

			while (remove != 'Y' && remove != 'y' && remove != 'N' && remove != 'n') {
				cout << "\nInvalid answer. Enter 'Y' or 'y' for YES, 'N' or 'n' for NO: ";
				cin >> remove;
			}

			if (remove == 'Y' || remove == 'y') {
				ShowRemovableItems(tv, phone, game, movie, book);
			}
		}
		else {
			remove = 'N';
		}
	} while (remove == 'Y' || remove == 'y');
}

void ItemRemoval(int ItemToRemove, int &QuantityToRemove, int &tv, int &phone, int &game, double &movie, int &book) {

	bool flag = false;
	int CurrentQuantity, SelectedID = ItemToRemove - 1;

	for (int h = 0, i = 0; i < TOTAL_ITEMS; i++) {

		if (h == 0 && i - 1 == TV_AMOUNT) {
			UPDATE_ID_LIST;
		}
		else if (h == 1 && i - 1 == PHONES_AMOUNT) {
			UPDATE_ID_LIST;
		}
		else if (h == 2 && i - 1 == VIDEOGAMES_AMOUNT) {
			UPDATE_ID_LIST;
		}
		else if (h == 3 && i - 1 == MOVIES_AMOUNT) {
			UPDATE_ID_LIST;
		}

		if (ItemToRemove == ITEMS_ID[h][i]) {
			if (ItemToRemove <= MAX_TV_ID) {
				if (ItemToRemove <= 5) {
					CurrentQuantity = TVSelected[0][SelectedID];
				}
				else if (ItemToRemove <= 10) {
					CurrentQuantity = TVSelected[1][SelectedID - 5];
				}
				else if (ItemToRemove <= 15) {
					CurrentQuantity = TVSelected[2][SelectedID - 10];
				}
				else if (ItemToRemove <= 20) {
					CurrentQuantity = TVSelected[3][SelectedID - 15];
				}
				else {
					CurrentQuantity = TVSelected[4][SelectedID - 20];
				}

				QuantityRemovalValidation(ItemToRemove, CurrentQuantity, QuantityToRemove, flag);


				for (int j = 0, k = 1, y = 0; flag != true; j++, k++) {

					if (j - 1 == 5) {
						LOOP_ID_UPDATE_1;
					}
					if (ItemToRemove == k) {
						tv -= QuantityToRemove * TVPrices[y][j];
						TVSelected[y][j] -= QuantityToRemove;
						flag = true;
					}
				}
			}

			else if (ItemToRemove <= MAX_PHONE_ID) {
				if (ItemToRemove <= 30) {
					CurrentQuantity = PhoneSelected[0][SelectedID - 25];
				}
				else if (ItemToRemove <= 35) {
					CurrentQuantity = PhoneSelected[1][SelectedID - 30];
				}
				else if (ItemToRemove <= 39) {
					CurrentQuantity = PhoneSelected[2][SelectedID - 35];
				}
				else if (ItemToRemove <= 44) {
					CurrentQuantity = PhoneSelected[3][SelectedID - 39];
				}
				else {
					CurrentQuantity = PhoneSelected[4][SelectedID - 44];
				}

				QuantityRemovalValidation(ItemToRemove, CurrentQuantity, QuantityToRemove, flag);


				for (int j = 0, k = MAX_TV_ID + 1, y = 0; flag != true; k++, j++) {

					if (k - 1 == 30) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 35) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 39) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 44) {
						LOOP_ID_UPDATE_1;
					}

					if (ItemToRemove == k) {
						phone -= QuantityToRemove * PhonePrices[y][j];
						PhoneSelected[y][j] -= QuantityToRemove;
						flag = true;
					}
				}
			}

			else if (ItemToRemove <= MAX_VIDEOGAME_ID) {

				CurrentQuantity = VideogamesSelected[SelectedID - 49];

				QuantityRemovalValidation(ItemToRemove, CurrentQuantity, QuantityToRemove, flag);

				for (int k = MAX_PHONE_ID + 1; flag != true; k++) {

					if (ItemToRemove == k) {
						game -= QuantityToRemove * VideogamesPrices[k];
						VideogamesSelected[k] -= QuantityToRemove;
						flag = true;
					}
				}
			}

			else if (ItemToRemove <= MAX_MOVIE_ID) {
				if (ItemToRemove <= 103) {
					CurrentQuantity = MoviesSelected[0][SelectedID - 79];
				}
				else if (ItemToRemove <= 128) {
					CurrentQuantity = MoviesSelected[1][SelectedID - 104];
				}

				QuantityRemovalValidation(ItemToRemove, CurrentQuantity, QuantityToRemove, flag);

				for (int j = 0, k = MAX_VIDEOGAME_ID + 1, y = 0; flag != true; k++, j++) {

					if (k - 1 == 103) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 128) {
						LOOP_ID_UPDATE_1;

						if (ItemToRemove == k) {
							movie -= QuantityToRemove * MoviesPriceDVD_BLURAY[y][j];
							MoviesSelected[y][j] -= QuantityToRemove;
							flag = true;
						}
					}
				}
			}

			else if (ItemToRemove <= MAX_BOOK_ID) {

				if (ItemToRemove <= 132) {
					CurrentQuantity = BookSelected[0][SelectedID - 129];
				}
				else if (ItemToRemove <= 139) {
					CurrentQuantity = BookSelected[1][SelectedID - 132];
				}
				else if (ItemToRemove <= 143) {
					CurrentQuantity = BookSelected[2][SelectedID - 139];
				}
				else if (ItemToRemove == 144) {
					CurrentQuantity = BookSelected[3][0];
				}
				else if (ItemToRemove == 145) {
					CurrentQuantity = BookSelected[4][0];
				}
				else if (ItemToRemove == 146) {
					CurrentQuantity = BookSelected[5][0];
				}
				else if (ItemToRemove == 147) {
					CurrentQuantity = BookSelected[6][0];
				}
				else {
					CurrentQuantity = BookSelected[7][0];
				}

				QuantityRemovalValidation(ItemToRemove, CurrentQuantity, QuantityToRemove, flag);

				for (int j = 0, k = MAX_MOVIE_ID + 1, y = 0; flag != true; k++, j++) {

					if (k - 1 == 132) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 139) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 143) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 144) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 145) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 146) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 147) {
						LOOP_ID_UPDATE_1;
					}
					else if (k - 1 == 148) {
						LOOP_ID_UPDATE_1;
					}
					if (ItemToRemove == k) {
						book -= QuantityToRemove * BooksPrices[y][j];
						BookSelected[y][j] -= QuantityToRemove;
						flag = true;
					}
				}
			}
			else {
				CLEAR;
				cout << "The ID #" << ItemToRemove << " number does not match any of the current items in your cart!\n\n";
				PAUSE;
			}

			if (flag) {
				i = TOTAL_ITEMS;
				CLEAR;
				if (QuantityToRemove > 0) {
					cout << "Succesfully deleted " << QuantityToRemove << " items of the ID #"
						<< ItemToRemove << " number from your cart!\n\n";
				}
				else {
					cout << "Succesfully cancelled the removal of the item with ID #" << ItemToRemove
						<< " number from your cart!\n\n";
				}
				PAUSE;
			}
		}
	}
}

void QuantityRemovalValidation(int ItemToRemove, int &CurrentQuantity, int &QuantityToRemove, bool &flag) {
	
	while (QuantityToRemove > CurrentQuantity || QuantityToRemove < 0) {
		cout << "\nInvalid Quantity. You currently have " << CurrentQuantity
			<< " items with the ID number " << ItemToRemove << ".\n"
			<< "Enter a quantity equal to zero to cancel, or lower than " << CurrentQuantity << ": ";
		cin >> QuantityToRemove;
	}

	if (QuantityToRemove == 0) {
		flag = true;
	}
}
