/* Including libraries */
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include <fstream>
#include <random>
#include <time.h>
#include<cstring>

using namespace std;
using namespace sf;



/* Function used to draw texts on screen at different positions */
void textDraw(int score, int highScorePrint, Text& scoreText, RenderWindow& window, Text& highscoreText, char where, int highscoresarray[10], Text& highScoresList) {
	stringstream ss;
	if (where == 'g')
	{
		ss << "Score: " << score << endl;
		ss << "High Score: " << highscoresarray[0];
		scoreText.setString(ss.str());
		scoreText.setString(ss.str());
	}
	if (where == 'o') {
		ss.str("");
		ss << "1. " << highscoresarray[0] << endl;
		ss << "2. " << highscoresarray[1] << endl;
		ss << "3. " << highscoresarray[2] << endl;
		ss << "4. " << highscoresarray[3] << endl;
		ss << "5. " << highscoresarray[4] << endl;
		ss << "6. " << highscoresarray[5] << endl;
		ss << "7. " << highscoresarray[6] << endl;
		ss << "8. " << highscoresarray[7] << endl;
		ss << "9. " << highscoresarray[8] << endl;
		ss << "10. " << highscoresarray[9];
		scoreText.setScale(1, 1);
		scoreText.setString(ss.str());
		scoreText.setPosition(1050, 120);
		scoreText.setFillColor(Color::Black);
	}
}


/* Randomizing values from 2 arrays - For Pipes yPosition */
int otherrandomizer() {
	int randoms[2] = { 1, 2 };
	int randomnum = rand() % 2;
	return randoms[randomnum];
}

/* Detecting collisions */
bool collisionDetection(Sprite& birdySprite, Sprite& UpipeSprite, Sprite& U1pipeSprite, Sprite& U2pipeSprite, Sprite& IpipeSprite, Sprite& I1pipeSprite, Sprite& I2pipeSprite) {
	bool isIntersecting = false;
	float minus = 16;
	FloatRect rangerU = UpipeSprite.getGlobalBounds(); FloatRect rangerU1 = U1pipeSprite.getGlobalBounds(); FloatRect rangerU2 = U2pipeSprite.getGlobalBounds();
	rangerU.left += minus; rangerU1.left += minus; rangerU2.left += minus;
	FloatRect rangerI = IpipeSprite.getGlobalBounds(); FloatRect rangerI1 = I1pipeSprite.getGlobalBounds(); FloatRect rangerI2 = I2pipeSprite.getGlobalBounds();
	rangerI.left += minus; rangerI1.left += minus; rangerI2.left += minus;
	if (birdySprite.getGlobalBounds().intersects(rangerU))
	{
		isIntersecting = true;
	}
	else if (birdySprite.getGlobalBounds().intersects(rangerU1))
	{
		isIntersecting = true;
	}
	else if (birdySprite.getGlobalBounds().intersects(rangerU2))
	{
		isIntersecting = true;
	}
	else if (birdySprite.getGlobalBounds().intersects(rangerI))
	{
		isIntersecting = true;
	}
	else if (birdySprite.getGlobalBounds().intersects(rangerI1))
	{
		isIntersecting = true;
	}
	else if (birdySprite.getGlobalBounds().intersects(rangerI2))
	{
		isIntersecting = true;
	}
	return isIntersecting;
}


/* Randomizing values from 2 different arrays */
int randomizer() {
	int Urandoms[5] = { -600, -625, -550, -450, -400 };
	int Lrandoms[5] = { -350, -300, -325, -250, -280 };

	int randomnum = rand() % 5;

	int check = otherrandomizer();

	if (check == 1) {
		return Urandoms[randomnum];
	}
	else {
		return Lrandoms[randomnum];
	}

}

/* Drawing background */
void bkgDraw(RenderWindow& window) {
	Texture bkgTexture;
	Sprite bkgSprite;
	if (!bkgTexture.loadFromFile("assets//images//background.png"))
	{
		cout << "Couldn't load image. Please retry" << endl;
	}
	Vector2u bkgtexturesize = bkgTexture.getSize();
	float bkgX = (float)1360 / bkgtexturesize.x;
	float bkgY = (float)768 / bkgtexturesize.y;
	bkgSprite.setTexture(bkgTexture);
	bkgSprite.setScale(bkgX, bkgY);
	window.draw(bkgSprite);
}


/* All the functions below are used to move and draw pipes */
void UpipeDraw(RenderWindow& window, Sprite& UpipeSprite)
{
	window.draw(UpipeSprite);
}

void UpipeMove(Sprite& UpipeSprite, int speed)
{
	UpipeSprite.move(speed, 0);
}

void IpipeDraw(RenderWindow& window, Sprite& IpipeSprite)
{
	window.draw(IpipeSprite);
}

void IpipeMove(Sprite& IpipeSprite, int speed)
{
	IpipeSprite.move(speed, 0);
}

void U1pipeDraw(RenderWindow& window, Sprite& U1pipeSprite)
{
	window.draw(U1pipeSprite);
}

void U1pipeMove(Sprite& U1pipeSprite, int speed)
{
	U1pipeSprite.move(speed, 0);
}

void I1pipeDraw(RenderWindow& window, Sprite& I1pipeSprite)
{
	window.draw(I1pipeSprite);
}

void I1pipeMove(Sprite& I1pipeSprite, int speed)
{
	I1pipeSprite.move(speed, 0);
}

void U2pipeDraw(RenderWindow& window, Sprite& U2pipeSprite)
{
	window.draw(U2pipeSprite);
}

void U2pipeMove(Sprite& U2pipeSprite, int speed)
{
	U2pipeSprite.move(speed, 0);
}

void I2pipeDraw(RenderWindow& window, Sprite& I2pipeSprite)
{
	window.draw(I2pipeSprite);
}

void I2pipeMove(Sprite& I2pipeSprite, int speed)
{
	I2pipeSprite.move(speed, 0);
}

void highscoresort(int currentscore, int highscoresarray[10]) {

	int temp = 0;
	int temp2 = 0;
	for (int i = 0; i < 10; i++) {
		if (currentscore > highscoresarray[i]) {
			temp = highscoresarray[i];
			highscoresarray[i] = currentscore;
			for (int j = i + 1; j < 10; j++) {
				temp2 = highscoresarray[j];
				highscoresarray[j] = temp;
				temp = temp2;

			}

			return;
		}
	}
	return;
}


/* Main Function */
int main() {

	/* Making some initializations */
	Vector2f saveBirdypos;
	Vector2f saveUpipepos;
	Vector2f saveU1pipepos;
	Vector2f saveU2pipepos;
	Vector2f saveIpipepos;
	Vector2f saveI1pipepos;
	Vector2f saveI2pipepos;
	int savescore = 0;
	int highscoresarray[10] = {};
	int score = 0;
	int currentscore = 0;
	bool muteSound = false;
	float gravity = 0.25f;
	float jump = -4.0f;
	float velocity = 0.0f;



	/* Opening file for storing high scores */
	ifstream scores;
	scores.open("assets//txt//high_scores.txt");
	for (int i = 0; i < 10; i++) {
		scores >> highscoresarray[i];
		cout << endl;
	}
	scores.close();

	/* File handling for game state */
	ifstream gamestate;
	gamestate.open("assets//txt//game_state.txt");
	gamestate >> saveBirdypos.x;
	gamestate >> saveUpipepos.x;
	gamestate >> saveU1pipepos.x;
	gamestate >> saveU2pipepos.x;
	gamestate >> saveIpipepos.x;
	gamestate >> saveI1pipepos.x;
	gamestate >> saveI2pipepos.x;
	gamestate >> saveBirdypos.y;
	gamestate >> saveUpipepos.y;
	gamestate >> saveU1pipepos.y;
	gamestate >> saveU2pipepos.y;
	gamestate >> saveIpipepos.y;
	gamestate >> saveI1pipepos.y;
	gamestate >> saveI2pipepos.y;
	gamestate >> savescore;
	gamestate.close();

	RenderWindow window(VideoMode(1360, 768), "window", Style::Resize | Style::Titlebar);

	srand(time(0));



	/* Initializing Birdy Sprite*/
	Texture birdyTexture;
	Sprite birdySprite;
	if (!birdyTexture.loadFromFile("assets//images//franky.png"))
	{
		cout << "Couldn't load sheet. Please retry!" << endl;
	}
	float birdyPosx = 0.2f * 1360;
	float birdyPosy = 0.5f * 768;
	float scale = 0.15;
	birdySprite.setPosition(birdyPosx, birdyPosy);
	birdySprite.setScale(scale, scale);


	/* Drawing the select sprite page */
	Texture spritePageTexture;
	Sprite spritePageSprite;
	if (!spritePageTexture.loadFromFile("assets//images//costume-page.png"))
	{
		cout << "Couldn't load sprite selection page. Please retry!" << endl;
	}
	spritePageSprite.setTexture(spritePageTexture);
	Vector2u spritePagetexturesize = spritePageTexture.getSize();
	float spritePagewindowScaleX = (float)1360 / spritePagetexturesize.x;
	float spritePagewindowScaleY = (float)768 / spritePagetexturesize.y;
	spritePageSprite.setScale(spritePagewindowScaleX, spritePagewindowScaleY);
	spritePageSprite.setPosition(0, 0);


	/* Drawing selections for franky */
	Texture franky1;
	Texture franky2;
	if (!franky1.loadFromFile("assets//images//x-rayfranky.png"))
	{
		cout << "Couldn't load X-Ray Franky! Please retry... " << endl;
	}
	if (!franky2.loadFromFile("assets//images//high-gfranky.png"))
	{
		cout << "Couldn't load High-G Franky! Please retry... " << endl;
	}


	/* Below are the text and font initializations*/
	Font font;
	if (!font.loadFromFile("assets//others//font.ttf")) {
		cout << "Error loading font";
	}
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setFillColor(Color::Black);
	scoreText.setScale((float)2, (float)2);
	float ScoreX = 0.9f * window.getSize().x;
	float ScoreY = 0.1f * window.getSize().y;
	scoreText.setPosition(ScoreX, ScoreY);

	Text highScoreText;
	highScoreText.setFont(font);
	scoreText.setScale((float)2, (float)2);
	scoreText.setPosition(900, 40);
	int highScorePrint = highscoresarray[0];


	Text highScoreString;
	highScoreString.setFont(font);
	scoreText.setFillColor(Color::Black);
	scoreText.setScale((float)2, (float)2);
	scoreText.setPosition(900, 40);

	Text highScoresList;
	highScoresList.setFont(font);
	scoreText.setFillColor(Color::Black);
	scoreText.setScale((float)2, (float)2);
	scoreText.setPosition(900, 0);

	Text muteMusic;
	muteMusic.setFont(font);
	muteMusic.setFillColor(Color::Black);
	muteMusic.setScale((float)1.2, (float)1.2);
	muteMusic.setPosition(900, 20);
	string muteString = "Press M to Mute \n Press U to unmute \n the baclground music";
	muteMusic.setString(muteString);


	/* Initializing texture for menu */
	Texture menuTexture;
	Sprite menuSprite;
	if (!menuTexture.loadFromFile("assets//images//bkg-menu.png"))
	{
		cout << "Couldn't load menu. Please retry!" << endl;
	}
	menuSprite.setTexture(menuTexture);
	Vector2u menutexturesize = menuTexture.getSize();
	float menuScaleX = (float)1360 / menutexturesize.x;
	float menuScaleY = (float)768 / menutexturesize.y;
	menuSprite.setScale(menuScaleX, menuScaleY);
	menuSprite.setPosition(0, 0);


	/* Initializing texture for high score window */
	Texture highwindowTexture;
	Sprite highwindowSprite;
	if (!highwindowTexture.loadFromFile("assets//images//highscorepage.png"))
	{
		cout << "Couldn't load high window. Please retry!" << endl;
	}
	highwindowSprite.setTexture(highwindowTexture);
	Vector2u highwindowtexturesize = highwindowTexture.getSize();
	float highwindowScaleX = (float)1360 / highwindowtexturesize.x;
	float highwindowScaleY = (float)768 / highwindowtexturesize.y;
	highwindowSprite.setScale(highwindowScaleX, highwindowScaleY);
	highwindowSprite.setPosition(0, 0);


	/* Initializing texture for buttons */
	Texture playTexture;
	Sprite playSprite;
	float playPosx = 0.7f * window.getPosition().x;
	float playPosy = 240;
	float playscale = 0.35;
	if (!playTexture.loadFromFile("assets//images//playbutton.png"))
	{
		cout << "Couldn't load play. Please retry!" << endl;
	}
	playSprite.setTexture(playTexture);
	playSprite.setScale(playscale, playscale);
	playSprite.setPosition(playPosx, playPosy);

	Texture resumeTexture;
	Sprite resumeSprite;
	float resumePosx = 0.7f * window.getPosition().x;
	float resumePosy = 350;
	float resumescale = 0.35;
	if (!resumeTexture.loadFromFile("assets//images//resumebutton.png"))
	{
		cout << "Couldn't load resume. Please retry!" << endl;
	}
	resumeSprite.setTexture(resumeTexture);
	resumeSprite.setScale(resumescale, resumescale);
	resumeSprite.setPosition(resumePosx, resumePosy);


	Texture highScoreButton;
	Sprite highScoreButtonSprite;
	float highScorePosx = 0.69f * window.getPosition().x;
	float highScorePosy = 450;
	float highScoreScale = 0.35;
	if (!highScoreButton.loadFromFile("assets//images//highscorebutton.png"))
	{
		cout << "Couldn't load resume. Please retry!" << endl;
	}
	highScoreButtonSprite.setTexture(highScoreButton);
	highScoreButtonSprite.setScale(highScoreScale, highScoreScale);
	highScoreButtonSprite.setPosition(highScorePosx, highScorePosy);



	/* Initializing texture for pause screen */
	Texture pauseTexture;
	Sprite pauseSprite;
	if (!pauseTexture.loadFromFile("assets//images//pause.png"))
	{
		cout << "Couldn't load pause. Please retry!" << endl;
	}
	pauseSprite.setTexture(pauseTexture);
	float pauseScaleX = (float)1360 / pauseTexture.getSize().x;
	float pauseScaleY = (float)768 / pauseTexture.getSize().y;
	pauseSprite.setScale(pauseScaleX, pauseScaleY);
	pauseSprite.setPosition(0, 0);


	/* Initializing texture for game over */
	Texture overTexture;
	Sprite overSprite;
	if (!overTexture.loadFromFile("assets//images//gameover.png"))
	{
		cout << "Couldn't load over. Please retry!" << endl;
	}
	overSprite.setTexture(overTexture);
	float overScaleX = (float)1360 / overTexture.getSize().x;
	float overScaleY = (float)768 / overTexture.getSize().y;
	overSprite.setScale(overScaleX, overScaleY);
	overSprite.setPosition(0, 0);


	/* Initializing texture for mute and unmute */
	Texture muteTexture;
	Sprite muteSprite;
	if (!muteTexture.loadFromFile("assets//images//mute.png"))
	{
		cout << "Couldn't load mute image. Please retry!" << endl;
	}
	muteSprite.setTexture(muteTexture);
	float muteScaleX = 1.8;
	float muteScaleY = 1.8;
	muteSprite.setScale(muteScaleX, muteScaleY);
	muteSprite.setPosition(1200, 650);

	Texture unmuteTexture;
	Sprite unmuteSprite;
	if (!unmuteTexture.loadFromFile("assets//images//unmute.png"))
	{
		cout << "Couldn't load unmute image. Please retry!" << endl;
	}
	unmuteSprite.setTexture(unmuteTexture);
	float unmuteScaleX = 1.8;
	float unmuteScaleY = 1.8;
	unmuteSprite.setScale(unmuteScaleX, unmuteScaleY);
	unmuteSprite.setPosition(1200, 650);


	/* Initializing Sounds */
	SoundBuffer errorBuffer;
	if (!errorBuffer.loadFromFile("game_over.wav"))
	{
		cout << "Couldn't load sound. Please retry!" << endl;
	}
	Sound errorSound;
	errorSound.setBuffer(errorBuffer);

	SoundBuffer jumpBuffer;
	if (!jumpBuffer.loadFromFile("audio_flap.wav"))
	{
		cout << "Couldn't load flap sound. Please retry!" << endl;
	}
	Sound jumpSound;
	jumpSound.setBuffer(jumpBuffer);

	SoundBuffer bkgMusicBuffer;
	Sound bkgMusic;
	if (!bkgMusicBuffer.loadFromFile("bkg.wav")) {
		cout << "Couldn't load background music. Please retry!" << endl;
	}
	bkgMusic.setBuffer(bkgMusicBuffer);

	SoundBuffer scoreBuffer;
	Sound scoreSound;
	if (!scoreBuffer.loadFromFile("score.wav"))
	{
		cout << "Couldn't load score sound. Please retry!" << endl;
	}
	scoreSound.setBuffer(scoreBuffer);


	/* Initializing Pipes */
	Texture UpipeTexture;
	Sprite UpipeSprite;
	float UpipePosx = 1360;
	float UpipePosy = randomizer();
	float Uscale = 1.25;
	if (!UpipeTexture.loadFromFile("assets//images//upipe.png"))
	{
		cout << "Couldn't load Upipe. Please retry!" << endl;
	}
	UpipeSprite.setTexture(UpipeTexture);
	UpipeSprite.setPosition(UpipePosx, UpipePosy);
	UpipeSprite.setScale(Uscale / 1.25, Uscale);
	Texture U1pipeTexture;
	Sprite U1pipeSprite;
	float U1pipePosx = 2000;
	float U1pipePosy = randomizer();
	float U1scale = 1.25;
	if (!U1pipeTexture.loadFromFile("assets//images//upipe.png"))
	{
		cout << "Couldn't load U1pipe. Please retry!" << endl;
	}
	U1pipeSprite.setTexture(U1pipeTexture);
	U1pipeSprite.setPosition(U1pipePosx, U1pipePosy);
	U1pipeSprite.setScale(U1scale / 1.25, U1scale);
	Texture U2pipeTexture;
	Sprite U2pipeSprite;
	float U2pipePosx = 2500;
	float U2pipePosy = randomizer();
	float U2scale = 1.25;
	if (!U2pipeTexture.loadFromFile("assets//images//upipe.png"))
	{
		cout << "Couldn't load U2pipe. Please retry!" << endl;
	}
	U2pipeSprite.setTexture(U2pipeTexture);
	U2pipeSprite.setPosition(U2pipePosx, U2pipePosy);
	U2pipeSprite.setScale(U2scale / 1.25, U2scale);



	Texture IpipeTexture;
	Sprite IpipeSprite;
	float IpipePosx = 1360;
	float IpipePosy;
	float Iscale = 1.25;
	if (!IpipeTexture.loadFromFile("assets//images//Ipipe.png"))
	{
		cout << "Couldn't load Ipipe. Please retry!" << endl;
	}
	IpipePosy = UpipePosy + 950;
	IpipeSprite.setTexture(IpipeTexture);
	IpipeSprite.setScale(Iscale / 1.25, Iscale);
	IpipeSprite.setPosition(IpipePosx, IpipePosy);
	IpipeSprite.move(0, -1);

	Texture I1pipeTexture;
	Sprite I1pipeSprite;
	float I1pipePosx = 2000;
	float I1pipePosy;
	float I1scale = 1.25;
	if (!I1pipeTexture.loadFromFile("assets//images//Ipipe.png"))
	{
		cout << "Couldn't load I1pipe. Please retry!" << endl;
	}
	I1pipePosy = U1pipePosy + 950;
	I1pipeSprite.setTexture(I1pipeTexture);
	I1pipeSprite.setScale(I1scale / 1.25, I1scale);
	I1pipeSprite.setPosition(I1pipePosx, I1pipePosy);
	I1pipeSprite.move(0, -1);

	Texture I2pipeTexture;
	Sprite I2pipeSprite;
	float I2pipePosx = 2500;
	float I2pipePosy;
	float I2scale = 1.25;
	if (!I2pipeTexture.loadFromFile("assets//images//Ipipe.png"))
	{
		cout << "Couldn't load Ipipe. Please retry!" << endl;
	}
	I2pipePosy = U2pipePosy + 950;
	I2pipeSprite.setTexture(I2pipeTexture);
	I2pipeSprite.setScale(I2scale / 1.25, I2scale);
	I2pipeSprite.setPosition(I2pipePosx, I2pipePosy);
	I2pipeSprite.move(0, -1);


	/* Some more initializations */
	bool gameStarted = false;
	bool paused = false;
	bool gameover = false;
	bool highwindow = false;
	bool resume = false;
	bool menudisplay = false;
	int speed = -2;
	bool spritePageDisplay = false;
	Vector2i mousepos = Mouse::getPosition(window);


	/* Window Opening */
	while (window.isOpen())
	{
		ofstream score1;
		Event theEvent;
		while (window.pollEvent(theEvent)) {
			mousepos = Mouse::getPosition(window);
			if (score >= 10) {
				speed = -3;
			}
			else if (score >= 20) {
				speed = -4;														// CHANGING SPEEDS W.R.T SCORES
			}
			else if (score >= 30) {
				speed = -5;
			}
			window.clear();

			if (theEvent.type == theEvent.Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {

				saveBirdypos = birdySprite.getPosition();
				saveUpipepos = UpipeSprite.getPosition();
				saveU1pipepos = U1pipeSprite.getPosition();
				saveU2pipepos = U2pipeSprite.getPosition();						// SAVING GAME STATE
				saveIpipepos = IpipeSprite.getPosition();
				saveI1pipepos = I1pipeSprite.getPosition();
				saveI2pipepos = I2pipeSprite.getPosition();
				savescore = score;
				ofstream gamestate;
				gamestate.open("assets//txt//game_state.txt");
				if (gamestate.is_open()) {
					gamestate << saveBirdypos.x << endl;
					gamestate << saveUpipepos.x << endl;
					gamestate << saveU1pipepos.x << endl;
					gamestate << saveU2pipepos.x << endl;
					gamestate << saveIpipepos.x << endl;
					gamestate << saveI1pipepos.x << endl;
					gamestate << saveI2pipepos.x << endl;						// SAVING GAME STATE IN FILE
					gamestate << saveBirdypos.y << endl;
					gamestate << saveUpipepos.y << endl;
					gamestate << saveU1pipepos.y << endl;
					gamestate << saveU2pipepos.y << endl;
					gamestate << saveIpipepos.y << endl;
					gamestate << saveI1pipepos.y << endl;
					gamestate << saveI2pipepos.y << endl;
					gamestate << savescore << endl;
				}
				gamestate.close();
				window.close();
			}
			if (playSprite.getGlobalBounds().contains(mousepos.x, mousepos.y)) {

				playTexture.loadFromFile("assets//images//playclicked.png");
				playSprite.setScale(0.8, 0.8);
				playSprite.setTexture(playTexture);
			}
			else {
				playTexture.loadFromFile("assets//images//playbutton.png");
				playSprite.setScale(0.5, 0.5);
				playSprite.setTexture(playTexture);
			}
			if (resumeSprite.getGlobalBounds().contains(mousepos.x, mousepos.y)) {
				resumeTexture.loadFromFile("assets//images//resumeclicked.png");
				resumeSprite.setScale(0.8, 0.8);
				resumeSprite.setTexture(resumeTexture);
			}
			else {
				resumeTexture.loadFromFile("assets//images//resumebutton.png");
				resumeSprite.setScale(0.5, 0.5);
				resumeSprite.setTexture(resumeTexture);							// CREATING BUTTONS ANIMATION

			}
			if (highScoreButtonSprite.getGlobalBounds().contains(mousepos.x, mousepos.y)) {
				highScoreButton.loadFromFile("assets//images//highscoreclicked.png");
				highScoreButtonSprite.setScale(0.8, 0.8);
				highScoreButtonSprite.setTexture(highScoreButton);
			}
			else {
				highScoreButton.loadFromFile("assets//images//highscorebutton.png");
				highScoreButtonSprite.setScale(0.7, 0.7);
				highScoreButtonSprite.setTexture(highScoreButton);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::BackSpace)) {
				highwindow = false;
			}

			if ((playSprite.getGlobalBounds().contains(mousepos.x, mousepos.y) && Mouse::isButtonPressed(Mouse::Button::Left)) || Keyboard::isKeyPressed(Keyboard::Key::Enter) && menudisplay) {
				gameStarted = true;
				paused = false;
			}
			if (!paused) {
				if (Keyboard::isKeyPressed(Keyboard::Key::P)) {
					paused = true;
					gameStarted = false;
				}

				else if (paused) {
					if (Keyboard::isKeyPressed(Keyboard::Key::P)) {
						paused = false;
						gameStarted = true;
					}
				}
			}
		}



		if (highScoreButtonSprite.getGlobalBounds().contains((mousepos.x), (mousepos.y)) && Mouse::isButtonPressed(Mouse::Button::Left)) {
			highwindow = true;
		}

		if (resumeSprite.getGlobalBounds().contains((mousepos.x), (mousepos.y)) && Mouse::isButtonPressed(Mouse::Button::Left)) {
			paused = false;
			gameStarted = true;
			resume = true;
		}
		if (resume == true) {
			birdySprite.setPosition(saveBirdypos);
			UpipeSprite.setPosition(saveUpipepos);
			U1pipeSprite.setPosition(saveU1pipepos);
			U2pipeSprite.setPosition(saveU2pipepos);								// RESUMING GAME
			IpipeSprite.setPosition(saveIpipepos);
			I1pipeSprite.setPosition(saveI1pipepos);
			I2pipeSprite.setPosition(saveI2pipepos);
			score = savescore;
			resume = false;
		}



		stringstream ss;
		if (!gameStarted) {
			if (!paused) {
				if (!menudisplay)
				{
					window.draw(spritePageSprite);
					if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
					{
						birdySprite.setTexture(birdyTexture);
						menudisplay = true;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
					{
						birdySprite.setTexture(franky1);								// SPRITE SELECTION
						menudisplay = true;
					}
					else if (Keyboard::isKeyPressed(Keyboard::Key::Num3))
					{
						birdySprite.setTexture(franky2);
						menudisplay = true;
					}
				}
				else if (highwindow == true) {
					muteMusic.setScale((float)1.2, (float)1.2);
					muteMusic.setPosition(900, 20);
					window.draw(highwindowSprite);
					ss.str("");
					ss << "1. " << highscoresarray[0] << endl;
					ss << "2. " << highscoresarray[1] << endl;
					ss << "3. " << highscoresarray[2] << endl;
					ss << "4. " << highscoresarray[3] << endl;
					ss << "5. " << highscoresarray[4] << endl;
					ss << "6. " << highscoresarray[5] << endl;
					ss << "7. " << highscoresarray[6] << endl;							// DISPLAYING HIGHSCORES
					ss << "8. " << highscoresarray[7] << endl;
					ss << "9. " << highscoresarray[8] << endl;
					ss << "10. " << highscoresarray[9];
					scoreText.setScale(1.3, 1.3);
					scoreText.setString(ss.str());
					scoreText.setPosition(600, 155);
					scoreText.setFillColor(Color::Black);
					window.draw(scoreText);
				}
				else if (highwindow == false && menudisplay) {
					window.draw(menuSprite);
					window.draw(highScoreButtonSprite);
					window.draw(playSprite);
					window.draw(resumeSprite);
				}
			}
			else if (paused) {
				muteMusic.setPosition(900, 20);											// MUTE MUSIC TEST DISPLAY
				window.draw(pauseSprite);
			}
		}
		else if (gameover) {

			textDraw(score, highScorePrint, highScoreString, window, highScoresList, 'o', highscoresarray, highScoresList);
			window.draw(overSprite);
			window.draw(highScoreString);
			birdyPosy = 0.5f * 768;
			velocity = 0;

			if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
				score = 0;
				currentscore = 0;
				birdySprite.setPosition(birdyPosx,320);

				UpipePosy = randomizer();
				U1pipePosy = randomizer();
				U2pipePosy = randomizer();
				IpipePosy = UpipePosy + 850;
				IpipeSprite.setPosition(1360, IpipePosy);
				I1pipePosy = U1pipePosy + 850;											// GAME FUNCTION - PIPES POSITIONS
				I1pipeSprite.setPosition(1860, I1pipePosy);
				I2pipePosy = U2pipePosy + 850;
				I2pipeSprite.setPosition(2360, I2pipePosy);
				UpipeSprite.setPosition(1360, UpipePosy);
				U1pipeSprite.setPosition(1860, U1pipePosy);
				U2pipeSprite.setPosition(2360, U2pipePosy);
				gameStarted = false;
				paused = false;
				gameover = false;

			}
		}
		else
		{
			muteMusic.setPosition(20, 640);

			if (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				velocity = jump;			// BIRDY GRAVITY AND JUMP
				if (!jumpSound.getStatus())
				{
					jumpSound.play();
				}
			}
			velocity += gravity;
			birdyPosy += velocity;
			if (birdySprite.getPosition().y>760)
			{
				velocity = 0;
			}
			birdySprite.setPosition(birdyPosx, birdyPosy);



			bool is_moving = true;
			Vector2f barrier = birdySprite.getPosition();
			float barrierx = barrier.x;
			float barriery = barrier.y;
			if (barriery < 50) {
				birdySprite.move(0, 3);													// BOUNDARIES FOR SCREEN
			}
			else if (barriery > 700) {
				birdySprite.move(0, -3);
			}



			bkgDraw(window);
			window.draw(birdySprite);													// DRAWING AND OTHER FUNCTIONS
			UpipeDraw(window, UpipeSprite);
			IpipeDraw(window, IpipeSprite);
			UpipeMove(UpipeSprite, speed);
			IpipeMove(IpipeSprite, speed);
			U1pipeDraw(window, U1pipeSprite);
			I1pipeDraw(window, I1pipeSprite);
			U1pipeMove(U1pipeSprite, speed);
			I1pipeMove(I1pipeSprite, speed);
			U2pipeDraw(window, U2pipeSprite);
			I2pipeDraw(window, I2pipeSprite);
			U2pipeMove(U2pipeSprite, speed);
			I2pipeMove(I2pipeSprite, speed);
			window.draw(scoreText);


			Vector2f Upipecheck = UpipeSprite.getPosition();
			Vector2f U1pipecheck = U1pipeSprite.getPosition();
			Vector2f U2pipecheck = U2pipeSprite.getPosition();

			if (Upipecheck.x < -100) {
				UpipePosy = randomizer();
				IpipePosy = UpipePosy + 850;                             					// LOOPING OF PLATFORMS
				UpipeSprite.setPosition(1450, UpipePosy);
				IpipeSprite.setPosition(1450, IpipePosy);
				score++;
				if (!scoreSound.getStatus())
				{
					scoreSound.play();
				}
			}


			if (U1pipecheck.x < -100) {
				U1pipePosy = randomizer();
				I1pipePosy = U1pipePosy + 850;                              				// LOOPING OF PLATFORMS
				U1pipeSprite.setPosition(1450, U1pipePosy);
				I1pipeSprite.setPosition(1450, I1pipePosy);
				score++;
				if (!scoreSound.getStatus())
				{
					scoreSound.play();
				}
			}

			if (U2pipecheck.x < -100) {
				U2pipePosy = randomizer();
				I2pipePosy = U2pipePosy + 850;                              				// LOOPING OF PLATFORMS
				U2pipeSprite.setPosition(1450, U2pipePosy);
				I2pipeSprite.setPosition(1450, I2pipePosy);
				score++;
				if (!scoreSound.getStatus())
				{
					scoreSound.play();
				}
			}


			if (collisionDetection(birdySprite, UpipeSprite, U1pipeSprite, U2pipeSprite, IpipeSprite, I1pipeSprite, I2pipeSprite))
			{
				errorSound.play();
				currentscore = score;														// COLLISION DETECTION AND OPERATIONS
				score = 0;
				speed = -2;
				textDraw(score, highScorePrint, scoreText, window, highScoreText, 'g', highscoresarray, highScoresList);
				gameover = true;
				highscoresort(currentscore, highscoresarray);

				score1.open("assets//txt//high_scores.txt");
				if (score1.is_open()) {
					for (int j = 0; j < 10; j++) {
						score1 << highscoresarray[j];
						score1 << endl;
					}
				}
				int speed = -2;
			}
		}
		if (birdySprite.getPosition().y > 760)
		{
			birdySprite.setPosition(birdyPosx,birdyPosy);
			gameover = true;
		}
		else if (birdySprite.getPosition().y < 0)
		{
			birdyPosy = 0;
		}
		window.draw(muteMusic);
		if (Keyboard::isKeyPressed(Keyboard::Key::M))
		{
			muteSound = false;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::U))
		{
			muteSound = true;
		}
		if (!muteSound)																		// BACKGROUND MUSIC LOGIC
		{
			window.draw(muteSprite);
			bkgMusic.play();
		}
		else if (muteSound)
		{
			window.draw(unmuteSprite);
		}
		textDraw(score, highScorePrint, scoreText, window, highScoreText, 'g', highscoresarray, highScoresList);
		score1.close();
		cout << birdySprite.getPosition().y << endl;;
		cout << velocity << endl;
		cout << gameover << endl;
		window.display();
	}
	return 0;
}
