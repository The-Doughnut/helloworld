#ifndef _UI_HPP
#define _UI_HPP

/**
 * An API for the user interface so we can opperate on different systems accordingly.
 *
 * TODO: maybe make this a "system"? instead of just an Ui. makes more sense i think because of filesystem access n all. Like, where would the "save" function be?
 */
struct Ui {
    virtual ~Ui();
    virtual void render() = 0;
};

#endif
