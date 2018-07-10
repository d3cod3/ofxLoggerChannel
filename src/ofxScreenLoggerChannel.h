//
//  ofxScreenLoggerChannel.h
//  ofxLoggerChannel
//
//  Created by Elias Zananiri on 2015-08-02.
//
//

#pragma once

#include "ofMain.h"
#include "ofxFontStash.h"

class ofxScreenLoggerChannel : public ofBaseLoggerChannel
{
public:
    ofxScreenLoggerChannel();
    ~ofxScreenLoggerChannel();

    void setup(string fontfile,int size);

    void setIsRetina();
    
    void log(ofLogLevel level, const string & module, const string & message);
    void log(ofLogLevel level, const string & module, const char* format, ...) OF_PRINTF_ATTR(4, 5);
    void log(ofLogLevel level, const string & module, const char* format, va_list args);
    
    void clear();
    void draw() const;
    
    void setMaxBufferCount(int maxBufferCount);  // 0 for no limit.
    int getMaxBufferCount() const;
    
    void setDrawBounds(const ofRectangle& drawBounds);
    const ofRectangle& getDrawBounds() const;
    
    void setBackgroundColor(const ofColor& backgroundColor);
    const ofColor& getBackgroundColor() const;
    
    void setTextColor(const ofColor& textColor);
    const ofColor& getTextColor() const;

    void setColors(const ofColor& nColor,const ofColor& wColor,const ofColor& eColor);
    
    void setPrefixTimestamp(bool bPrefixTimestamp);
    bool getPrefixTimestamp() const;
    
    void mouseDragged(ofMouseEventArgs& args);
    void mouseMoved(ofMouseEventArgs& args);
    void mouseScrolled(ofMouseEventArgs& args);
    
private:

    ofxFontStash            *font;
    int                     fontSize;
    bool                    isRetina;
    float                   retinaScale;
    int                     maxVisibleLines;

    std::list<string> _buffer;
    int _maxBufferCount;
    
    ofRectangle _drawBounds;
    ofColor _backgroundColor;
    ofColor _textColor;
    ofColor _noticeColor;
    ofColor _warningColor;
    ofColor _errorColor;
    bool _bPrefixTimestamp;
    
    bool _bMouseInside;
    int _scrollOffset;

};
