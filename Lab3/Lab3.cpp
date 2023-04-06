#include <iostream>
#include <vector>
#include <string>

using namespace std;

class device {
protected:
    int model = 1;
    bool state = false;
public:
    device()
    {
        cout << " *** create device *** \n";
    }
    device(int model, string charact, bool state = true) : model(model), state(state) {}
    virtual ~device() {
        cout << " # delete devise # ";
    }
    virtual void action() = 0;
    void activate()
    {
        cout << " --- activate the device --- \n";
        state = true;
    }
    void GetModel()
    {
        cout << " @ model " << model << endl;
    }
    void GetState()
    {
        cout << " @ state " << state << endl;
    }
};

class audio : virtual public device {
protected:
    int volue = 50;
public:
    audio() 
    {
        cout << " *** create audio *** \n";
    }
    audio(int volue) :volue(volue) {}
    ~audio()
    {
        cout << " # delete audio # \n";
    }
    void action() override {
        cout << "   Play the audio   \n";
    }
    void volueHigh()
    {
        if (volue <= 90)
        {
            volue += 10;
        }
        
    }
    void volueLow()
    {
        if (volue >= 10)
        {
            volue -= 10;
        }
        
    }
    void GetVolue()
    {
        cout << " @ volue " << volue << endl;
    }
};

class video : virtual public device {
protected:
    const int qualityMas[6] = { 180, 240, 360, 480, 720, 1080 };
    int quality = 4;
public:
    video()
    {
        cout << " *** create video *** \n";
    }
    ~video()
    {
        cout << " # delete video # \n";
    }
    void action() override {
        cout << "   Play the video   \n";
    }
    void qualityHigh()
    {
        if (quality < 6)
        {
            quality += 1;
        }
    }
    void qualityLow()
    {
        if (quality > 1)
        {
            quality -= 1;
        }
    }
    void GetQuality()
    {
        cout << " @ quality " << qualityMas[quality] << endl;
    }
};

class indicator : virtual public device {
protected:
    bool on_off = false;
public:
    indicator()
    {
        cout << " *** create indicator *** \n";
    }
    indicator(bool on_off) :on_off(on_off) {}
    ~indicator()
    {
        cout << " # delete indicator # \n";
    }
    void action() override {
        cout << "   indicator is on   \n";
    }
    void High()
    {
        on_off = true;
    }
    void Low()
    {
        on_off = false;
    }
    void GetOn_off()
    {
        cout << " @ on_off " << on_off << endl;
    }
};

class Computer final : public audio, public video {
protected:
    string processor = "AMD";
    int ram = 16;
    int rom = 1024;
    string video_card  = "RTX 3060";
public:
    Computer()
    {
        cout << " *** create Computer *** \n";
    }
    Computer(string processor, int ram, int rom, string video_card)
        : processor(processor), ram(ram), rom(rom), video_card(video_card) {}
    ~Computer()
    {
        cout << " # delete Computer # \n";
    }
    void action() override final {
        cout << "   Computer is ready to work   \n";
    }
    void programm()
    {
        cout << " --- start programm --- ";
    }
    void STOP_programm()
    {
        cout << " --- stop programm --- ";
    }
    void New_model(int model)
    {
        this->model = model;
    }
    void GetProcessor()
    {
        cout << " @ processor " << processor << endl;
    }
    void GetRamf()
    {
        cout << " @ ram " << ram << endl;
    }
    void GetRom()
    {
        cout << " @ rom " << rom << endl;
    }
    void GetVideo_card()
    {
        cout << " @ video_card " << video_card << endl;
    }
    void Status()
    {
        cout << "   Status:" << endl;
        cout << "      model - " << model << endl;
        cout << "      state - " << state << endl;
        cout << "      volue - " << volue << endl;
        cout << "      quality - " << qualityMas[quality] << endl;
        cout << "      processor - " << processor << endl;
        cout << "      ram - " << ram << endl;
        cout << "      rom - " << rom << endl;
        cout << "      video_card - " << video_card << endl;
    }
};

class Oscilloscope final : public indicator, public video {
protected:
    int length = 50;
    int scale = 100;
public:
    Oscilloscope()
    {
        cout << " *** create Oscilloscope *** \n";
    }
    Oscilloscope(int length, int scale) : length(length), scale(scale) {}
    ~Oscilloscope()
    {
        cout << " # delete Oscilloscope # \n";
    }
    void action() override final {
        cout << "   Oscilloscope is ready to work   \n";
    }
    void Connect_Arduino()
    {
        cout << " --- Connect Arduino --- \n";
    }
    void DisConnect_Arduino()
    {
        cout << " --- Disconnect Arduino --- \n";
    }
    void New_model(int model)
    {
        this->model = model;
    }
    void GetLength()
    {
        cout << " @ length " << length << endl;
    }
    void GetScale()
    {
        cout << " @ scale " << scale << endl;
    }
    void Status()
    {
        cout << "   Status:" << endl;
        cout << "      model - " << model << endl;
        cout << "      state - " << state << endl;
        cout << "      quality - " << qualityMas[quality] << endl;
        cout << "      indicator - " << on_off << endl;
        cout << "      length - " << length << endl;
        cout << "      scale - " << scale << endl;
    }
};

int main()
{
    Computer comp;
    comp.activate();
    comp.action();
    comp.Status();
    comp.New_model(5);
    comp.GetModel();
    comp.programm();
    comp.video::action();
    comp.GetQuality();
    comp.qualityHigh();
    comp.GetQuality();
    comp.audio::action();
    comp.GetVolue();
    comp.volueHigh();
    comp.GetVolue();
    comp.STOP_programm();
    comp.Status();
}
