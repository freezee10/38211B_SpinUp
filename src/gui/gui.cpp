#include "main.h"


/////////////////////////////////
//OBJECTS
/////////////////////////////////


lv_obj_t * blueBtn;
lv_obj_t * blueBtnLabel;

lv_obj_t * redBtn;
lv_obj_t * redBtnLabel;

lv_obj_t * skillsBtn;
lv_obj_t * skillsBtnLabel;

lv_obj_t * diagBtn;
lv_obj_t * diagBtnLabel;

lv_obj_t * scr0; //scrMain
lv_obj_t * scr1; //scrBlue
lv_obj_t * scr2; //scrRed
lv_obj_t * scr3; //scrSkills
lv_obj_t * scr4; //scrDiag

lv_obj_t * scr0Label; //scrMain
lv_obj_t * scr1Label; //scrBlue - displays current auto selected 
lv_obj_t * scr2Label; //scrRed - displays current auto selected 
lv_obj_t * scr3Label; //scrSkills - displays current auto selected 

const char * scr1BtnMap[] = {"0B", "1B", "2B", "\n", "3B", "4B", "5B", ""}; //scrBlue
const char * scr2BtnMap[] = {"0R", "1R", "2R", "\n", "3R", "4R", "5R", ""}; //scrRed                
const char * scr3BtnMap[] = {"0S", "1S", "2S", "\n", "3S", "4S", "5S", ""}; //scrSkills

lv_obj_t * scr1Btnm; //scrBlue 
lv_obj_t * scr2Btnm; //scrRed 
lv_obj_t * scr3Btnm; //scrSkills




/////////////////////////////////
//STYLES
/////////////////////////////////


static lv_style_t blueBtnStyleREL; //released style
static lv_style_t blueBtnStylePR; //pressed style

static lv_style_t redBtnStyleREL; //released style
static lv_style_t redBtnStylePR; //pressed style

static lv_style_t skillsBtnStyleREL; //released style
static lv_style_t skillsBtnStylePR; //pressed style

static lv_style_t diagBtnStyleREL; //released style
static lv_style_t diagBtnStylePR; //pressed style

static lv_style_t scr0Style;
static lv_style_t scr1Style;
static lv_style_t scr2Style;
static lv_style_t scr3Style;
static lv_style_t scr4Style;

static lv_style_t scr1BtnmStyleREL;
static lv_style_t scr1BtnmStylePR;

static lv_style_t scr2BtnmStyleREL;
static lv_style_t scr2BtnmStylePR;

static lv_style_t scr3BtnmStyleREL;
static lv_style_t scr3BtnmStylePR;




/////////////////////////////////
//BUTTON MAPS/GRIDS
/////////////////////////////////


static lv_res_t blueBtnmAction(lv_obj_t *, const char *)
{

    uint16_t btnid = lv_btnm_get_toggled(scr1Btnm);

    char buffer[2];
	sprintf(buffer, "%i", btnid);
    pros::delay(100);
	lv_label_set_text(scr1Label, buffer);

    btnid = lv_btnm_get_toggled(scr1Btnm);

    return LV_RES_OK;
}

static lv_res_t redBtnmAction(lv_obj_t *, const char *)
{


    return LV_RES_OK;
}

static lv_res_t skillsBtnmAction(lv_obj_t *, const char *)
{


    return LV_RES_OK;
}
 



/////////////////////////////////
//SCREENS
/////////////////////////////////


void scrMain()
{
    lv_style_copy(&scr0Style, &lv_style_plain);
    scr0Style.text.color = LV_COLOR_MAKE(255, 255, 255);
    scr0Style.body.main_color = LV_COLOR_MAKE(0, 0, 0);
    scr0Style.body.grad_color = LV_COLOR_MAKE(0, 0, 0);

    scr0 = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scr0, &scr0Style);
    lv_obj_set_size(scr0, 480, 240);

    scr0Label = lv_label_create(scr0, NULL);
    lv_label_set_style(scr0Label, &scr0Style);
    lv_label_set_text(scr0Label, "CLICK A BUTTON ON TOP TO SELECT YOUR AUTO");
    lv_obj_align(scr0Label, scr0, LV_ALIGN_CENTER, 0, 0);

    lv_scr_load(scr0);

}

void scrBlue()
{
    lv_style_copy(&scr1Style, &lv_style_plain);
    scr1Style.text.color = LV_COLOR_MAKE(0, 0, 0);
    scr1Style.body.main_color = LV_COLOR_MAKE(87, 168, 250);
    scr1Style.body.grad_color = LV_COLOR_MAKE(87, 168, 250);

    lv_style_copy(&scr1BtnmStyleREL, &lv_style_plain);
    scr1BtnmStyleREL.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scr1BtnmStyleREL.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    scr1BtnmStyleREL.body.radius = 6;
    scr1BtnmStyleREL.body.border.width = 2;
    scr1BtnmStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scr1BtnmStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&scr1BtnmStylePR, &lv_style_plain);
    scr1BtnmStylePR.body.main_color = LV_COLOR_MAKE(200, 200, 200);
    scr1BtnmStylePR.body.grad_color = LV_COLOR_MAKE(200, 200, 200);
    scr1BtnmStylePR.body.radius = 6;
    scr1BtnmStylePR.body.border.width = 2;
    scr1BtnmStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scr1BtnmStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    scr1 = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scr1, &scr1Style);
    lv_obj_set_size(scr1, 480, 240); 

    scr1Btnm = lv_btnm_create(scr1, NULL);
    lv_btnm_set_style(scr1Btnm, LV_BTNM_STYLE_BTN_REL, &scr1BtnmStyleREL);
    lv_btnm_set_style(scr1Btnm, LV_BTNM_STYLE_BTN_TGL_REL, &scr1BtnmStylePR);
    lv_btnm_set_style(scr1Btnm, LV_BTNM_STYLE_BTN_PR, &scr1BtnmStylePR);
    lv_btnm_set_style(scr1Btnm, LV_BTNM_STYLE_BTN_TGL_PR, &scr1BtnmStyleREL);
    lv_btnm_set_map(scr1Btnm, scr1BtnMap);
    lv_btnm_set_toggle(scr1Btnm, true, 0);
    lv_btnm_set_action(scr1Btnm, blueBtnmAction);
    lv_obj_set_size(scr1Btnm, 450, 100);
    lv_obj_align(scr1Btnm, scr1, LV_ALIGN_CENTER, 0, -25);

    scr1Label = lv_label_create(scr1, NULL);
    lv_label_set_style(scr1Label, &scr1Style);
    lv_label_set_text(scr1Label, "balls");
    lv_obj_align(scr1Label, scr1, LV_ALIGN_CENTER, 0, 50);

    lv_scr_load(scr1);

}

void scrRed()
{
    lv_style_copy(&scr2Style, &lv_style_plain);
    scr2Style.text.color = LV_COLOR_MAKE(255, 255, 255);
    scr2Style.body.main_color = LV_COLOR_MAKE(255, 100, 100);
    scr2Style.body.grad_color = LV_COLOR_MAKE(255, 100, 100);

    lv_style_copy(&scr2BtnmStyleREL, &lv_style_plain);
    scr2BtnmStyleREL.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scr2BtnmStyleREL.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    scr2BtnmStyleREL.body.radius = 6;
    scr2BtnmStyleREL.body.border.width = 2;
    scr2BtnmStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scr2BtnmStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&scr2BtnmStylePR, &lv_style_plain);
    scr2BtnmStylePR.body.main_color = LV_COLOR_MAKE(200, 200, 200);
    scr2BtnmStylePR.body.grad_color = LV_COLOR_MAKE(200, 200, 200);
    scr2BtnmStylePR.body.radius = 6;
    scr2BtnmStylePR.body.border.width = 2;
    scr2BtnmStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scr2BtnmStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    scr2 = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scr2, &scr2Style);
    lv_obj_set_size(scr2, 480, 240); 

    scr2Btnm = lv_btnm_create(scr2, NULL);
    lv_btnm_set_style(scr2Btnm, LV_BTNM_STYLE_BTN_REL, &scr2BtnmStyleREL);
    lv_btnm_set_style(scr2Btnm, LV_BTNM_STYLE_BTN_TGL_REL, &scr2BtnmStylePR);
    lv_btnm_set_style(scr2Btnm, LV_BTNM_STYLE_BTN_PR, &scr2BtnmStylePR);
    lv_btnm_set_style(scr2Btnm, LV_BTNM_STYLE_BTN_TGL_PR, &scr2BtnmStyleREL);
    lv_btnm_set_map(scr2Btnm, scr2BtnMap);
    lv_btnm_set_toggle(scr2Btnm, true, 0);
    lv_obj_set_size(scr2Btnm, 450, 100);
    lv_obj_align(scr2Btnm, scr2, LV_ALIGN_CENTER, 0, -25);

    lv_scr_load(scr2);
}

void scrSkills()
{
    lv_style_copy(&scr3Style, &lv_style_plain);
    scr3Style.text.color = LV_COLOR_MAKE(255, 255, 255);
    scr3Style.body.main_color = LV_COLOR_MAKE(255, 150, 150);
    scr3Style.body.grad_color = LV_COLOR_MAKE(255, 150, 150);

    scr3 = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scr3, &scr3Style);
    lv_obj_set_size(scr3, 480, 240); 

    lv_style_copy(&scr3BtnmStyleREL, &lv_style_plain);
    scr3BtnmStyleREL.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scr3BtnmStyleREL.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    scr3BtnmStyleREL.body.radius = 6;
    scr3BtnmStyleREL.body.border.width = 2;
    scr3BtnmStyleREL.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scr3BtnmStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&scr3BtnmStylePR, &lv_style_plain);
    scr3BtnmStylePR.body.main_color = LV_COLOR_MAKE(200, 200, 200);
    scr3BtnmStylePR.body.grad_color = LV_COLOR_MAKE(200, 200, 200);
    scr3BtnmStylePR.body.radius = 6;
    scr3BtnmStylePR.body.border.width = 2;
    scr3BtnmStylePR.body.border.color = LV_COLOR_MAKE(0, 0, 0);
    scr3BtnmStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    scr3Btnm = lv_btnm_create(scr3, NULL);
    lv_btnm_set_style(scr3Btnm, LV_BTNM_STYLE_BTN_REL, &scr3BtnmStyleREL);
    lv_btnm_set_style(scr3Btnm, LV_BTNM_STYLE_BTN_TGL_REL, &scr3BtnmStylePR);
    lv_btnm_set_style(scr3Btnm, LV_BTNM_STYLE_BTN_PR, &scr3BtnmStylePR);
    lv_btnm_set_style(scr3Btnm, LV_BTNM_STYLE_BTN_TGL_PR, &scr3BtnmStyleREL);
    lv_btnm_set_map(scr3Btnm, scr3BtnMap);
    lv_btnm_set_toggle(scr3Btnm, true, 0);
    lv_obj_set_size(scr3Btnm, 450, 100);
    lv_obj_align(scr3Btnm, scr3, LV_ALIGN_CENTER, 0, -25);

    lv_scr_load(scr3);
}



void scrDiag()
{
    lv_style_copy(&scr4Style, &lv_style_plain);
    scr4Style.text.color = LV_COLOR_MAKE(255, 255, 255);
    scr4Style.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    scr4Style.body.grad_color = LV_COLOR_MAKE(150, 150, 150);

    scr4 = lv_obj_create(NULL, NULL);
    lv_obj_set_style(scr4, &scr4Style);
    lv_obj_set_size(scr4, 480, 240); 

    lv_scr_load(scr4);
}




/////////////////////////////////
//BUTTON ACTIONS
/////////////////////////////////


static lv_res_t blueBtnAction(lv_obj_t * btn)
{
    //changes all buttons that arent blue to be disabled
    lv_btn_set_state(redBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(skillsBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(diagBtn, LV_BTN_STYLE_REL);

    scrBlue(); //load scrBlue

    return LV_RES_OK;
}

static lv_res_t redBtnAction(lv_obj_t * btn)
{
    //changes all buttons that arent red to be disabled
    lv_btn_set_state(blueBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(skillsBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(diagBtn, LV_BTN_STYLE_REL);

    scrRed(); //load scrBlue

    return LV_RES_OK;
}

static lv_res_t skillsBtnAction(lv_obj_t * btn)
{
    //changes all buttons that arent skills to be disabled
    lv_btn_set_state(blueBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(redBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(diagBtn, LV_BTN_STYLE_REL);

    scrSkills(); //load scrSkills

    return LV_RES_OK;
}

static lv_res_t diagBtnAction(lv_obj_t * btn)
{
    //changes all buttons that arent diagnostics to be disabled
    lv_btn_set_state(blueBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(redBtn, LV_BTN_STYLE_REL);
    lv_btn_set_state(skillsBtn, LV_BTN_STYLE_REL);

    scrDiag(); //load scrDiag

    return LV_RES_OK;
}




/////////////////////////////////
//BUTTONS
////////////////////////////////


void blueBtnTop()
{

    lv_style_copy(&blueBtnStyleREL, &lv_style_plain);
    blueBtnStyleREL.body.main_color = LV_COLOR_MAKE(0, 120, 250);
    blueBtnStyleREL.body.grad_color = LV_COLOR_MAKE(0, 120, 250);
    blueBtnStyleREL.body.radius = 0;
    blueBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&blueBtnStylePR, &lv_style_plain);
    blueBtnStylePR.body.main_color = LV_COLOR_MAKE(87, 168, 250);
    blueBtnStylePR.body.grad_color = LV_COLOR_MAKE(87, 168, 250);
    blueBtnStylePR.body.radius = 0;
    blueBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    blueBtn = lv_btn_create(lv_layer_top(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_toggle(blueBtn, true);
    lv_btn_set_action(blueBtn, LV_BTN_ACTION_CLICK, blueBtnAction); //set function to be called on button click
   
    lv_btn_set_style(blueBtn, LV_BTN_STYLE_REL, &blueBtnStyleREL); //set the released style
    lv_btn_set_style(blueBtn, LV_BTN_STYLE_TGL_PR, &blueBtnStylePR); //set the released style
   
    lv_btn_set_style(blueBtn, LV_BTN_STYLE_TGL_REL, &blueBtnStylePR); //set the pressed style
    lv_btn_set_style(blueBtn, LV_BTN_STYLE_PR, &blueBtnStylePR); //set the pressed style
    
    lv_obj_set_size(blueBtn, 120, 30); //set the button size
    lv_obj_align(blueBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0); //set the position to top mid
    

    blueBtnLabel = lv_label_create(blueBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(blueBtnLabel, "BLUE"); //sets label text

}

void redBtnTop()
{
    lv_style_copy(&redBtnStyleREL, &lv_style_plain);
    redBtnStyleREL.body.main_color = LV_COLOR_MAKE(255, 0, 0);
    redBtnStyleREL.body.grad_color = LV_COLOR_MAKE(255, 0, 0);
    redBtnStyleREL.body.radius = 0;
    redBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&redBtnStylePR, &lv_style_plain);
    redBtnStylePR.body.main_color = LV_COLOR_MAKE(255, 100, 100);
    redBtnStylePR.body.grad_color = LV_COLOR_MAKE(255, 100, 100);
    redBtnStylePR.body.radius = 0;
    redBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    redBtn = lv_btn_create(lv_layer_top(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_toggle(redBtn, true);
    lv_obj_set_free_num(redBtn, 0); //set button is to 0
    lv_btn_set_action(redBtn, LV_BTN_ACTION_CLICK, redBtnAction); //set function to be called on button click
    
    lv_btn_set_style(redBtn, LV_BTN_STYLE_REL, &redBtnStyleREL); //set the released style
    lv_btn_set_style(redBtn, LV_BTN_STYLE_TGL_PR, &redBtnStylePR); //set the released style
   
    lv_btn_set_style(redBtn, LV_BTN_STYLE_TGL_REL, &redBtnStylePR); //set the pressed style
    lv_btn_set_style(redBtn, LV_BTN_STYLE_PR, &redBtnStylePR); //set the pressed style
    
    lv_obj_set_size(redBtn, 120, 30); //set the button size
    lv_obj_align(redBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 120, 0); //set the position to top mid

    redBtnLabel = lv_label_create(redBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(redBtnLabel, "RED"); //sets label text
}

void skillsBtnTop()
{
    lv_style_copy(&skillsBtnStyleREL, &lv_style_plain);
    skillsBtnStyleREL.body.main_color = LV_COLOR_MAKE(0, 120, 250);
    skillsBtnStyleREL.body.grad_color = LV_COLOR_MAKE(255, 0, 0);
    skillsBtnStyleREL.body.radius = 0;
    skillsBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&skillsBtnStylePR, &lv_style_plain);
    skillsBtnStylePR.body.main_color = LV_COLOR_MAKE(87, 168, 250);
    skillsBtnStylePR.body.grad_color = LV_COLOR_MAKE(255, 150, 150);
    skillsBtnStylePR.body.radius = 0;
    skillsBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    skillsBtn = lv_btn_create(lv_layer_top(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_toggle(skillsBtn, true);
    lv_obj_set_free_num(skillsBtn, 0); //set button is to 0
    lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, skillsBtnAction); //set function to be called on button click
    
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_REL, &skillsBtnStyleREL); //set the released style
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_TGL_PR, &skillsBtnStylePR); //set the released styleq
   
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_TGL_REL, &skillsBtnStylePR); //set the pressed style
    lv_btn_set_style(skillsBtn, LV_BTN_STYLE_PR, &skillsBtnStylePR); //set the pressed style
    
    lv_obj_set_size(skillsBtn, 120, 30); //set the button size
    lv_obj_align(skillsBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 0); //set the position to top mid

    skillsBtnLabel = lv_label_create(skillsBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(skillsBtnLabel, "SKILLS"); //sets label text
}

void diagBtnTop()
{
    lv_style_copy(&diagBtnStyleREL, &lv_style_plain);
    diagBtnStyleREL.body.main_color = LV_COLOR_MAKE(79, 79, 79);
    diagBtnStyleREL.body.grad_color = LV_COLOR_MAKE(79, 79, 79);
    diagBtnStyleREL.body.radius = 0;
    diagBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&diagBtnStylePR, &lv_style_plain);
    diagBtnStylePR.body.main_color = LV_COLOR_MAKE(150, 150, 150);
    diagBtnStylePR.body.grad_color = LV_COLOR_MAKE(150, 150, 150);
    diagBtnStylePR.body.radius = 0;
    diagBtnStylePR.text.color = LV_COLOR_MAKE(0, 0, 0);

    diagBtn = lv_btn_create(lv_layer_top(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_toggle(diagBtn, true);
    lv_obj_set_free_num(diagBtn, 0); //set button is to 0
    lv_btn_set_action(diagBtn, LV_BTN_ACTION_CLICK, diagBtnAction); //set function to be called on button click
    
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_REL, &diagBtnStyleREL); //set the released style
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_TGL_PR, &diagBtnStylePR); //set the released style
   
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_TGL_REL, &diagBtnStylePR); //set the pressed style
    lv_btn_set_style(diagBtn, LV_BTN_STYLE_PR, &diagBtnStylePR); //set the pressed style
    
    lv_obj_set_size(diagBtn, 120, 30); //set the button size
    lv_obj_align(diagBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 360, 0); //set the position to top mid

    diagBtnLabel = lv_label_create(diagBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(diagBtnLabel, "DIAG"); //sets label text
}





/////////////////////////////////
//INITIALIZE
/////////////////////////////////


void guiInit()
{
    blueBtnTop();
    diagBtnTop();
    redBtnTop();
    skillsBtnTop();
}