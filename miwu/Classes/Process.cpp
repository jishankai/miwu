//
//  Process.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Process.h"

#include "cocos2d.h"
#include "ProcessLoader.h"
#include "Load.h"
#include "StaticData.h"
#include "JsonBox.h"
#include "NormalGameScene.h"
#include "MouseGameScene.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;

int Process::mapType = 1;
int Process::levelNum = 1;

void Process::onEnter()
{
    LayerWithDialog::onEnter();
    level_ri->setPositionX(level_ri->getPositionX()-480*(mapType-1));
    level_west->setPositionX(level_west->getPositionX()-480*(mapType-1));
    level_tale->setPositionX(level_tale->getPositionX()-480*(mapType-1));
    level_cn->setPositionX(level_cn->getPositionX()-480*(mapType-1));
    level_evil->setPositionX(level_evil->getPositionX()-480*(mapType-1));
    setProcess();
    
    this->setTouchEnabled(true);
}

void Process::setProcess()
{
    int level = Load::sharedPlayer.level;
    //int level = 119;
    JsonBox::Array levels = Load::sharedPlayer.process;
    
    for (int i=0; i<level; i++) {
        int stars = atoi(levels[i]["stars"].getString().c_str());
        //int stars = 0;
        if (i==0) {
            level1->setVisible(true);
            setStars(level1, stars);
            continue;
        }
        if (i==1) {
            level2->setVisible(true);
            setStars(level2, stars);
            continue;
        }
        if (i==2) {
            level3->setVisible(true);
            setStars(level3, stars);
            continue;
        }
        if (i==3) {
            level4->setVisible(true);
            setStars(level4, stars);
            continue;
        }
        if (i==4) {
            level5->setVisible(true);
            setStars(level5, stars);
            continue;
        }
        if (i==5) {
            level6->setVisible(true);
            setStars(level6, stars);
            continue;
        }
        if (i==6) {
            level7->setVisible(true);
            setStars(level7, stars);
            continue;
        }
        if (i==7) {
            level8->setVisible(true);
            setStars(level8, stars);
            continue;
        }
        if (i==8) {
            level9->setVisible(true);
            setStars(level9, stars);
            continue;
        }
        if (i==9) {
            level10->setVisible(true);
            setStars(level10, stars);
            continue;
        }
        if (i==10) {
            level11->setVisible(true);
            setStars(level11, stars);
            continue;
        }
        if (i==11) {
            level12->setVisible(true);
            setStars(level12, stars);
            continue;
        }
        if (i==12) {
            level13->setVisible(true);
            setStars(level13, stars);
            continue;
        }
        if (i==13) {
            level14->setVisible(true);
            setStars(level14, stars);
            continue;
        }
        if (i==14) {
            level15->setVisible(true);
            setStars(level15, stars);
            continue;
        }
        if (i==15) {
            level16->setVisible(true);
            setStars(level16, stars);
            continue;
        }
        if (i==16) {
            level17->setVisible(true);
            setStars(level17, stars);
            continue;
        }
        if (i==17) {
            level18->setVisible(true);
            setStars(level18, stars);
            continue;
        }
        if (i==18) {
            level19->setVisible(true);
            setStars(level19, stars);
            continue;
        }
        if (i==19) {
            level20->setVisible(true);
            setStars(level20, stars);
            continue;
        }
        if (i==20) {
            level21->setVisible(true);
            setStars(level21, stars);
            continue;
        }
        if (i==21) {
            level22->setVisible(true);
            setStars(level22, stars);
            continue;
        }
        if (i==22) {
            level23->setVisible(true);
            setStars(level23, stars);
            continue;
        }
        if (i==23) {
            level24->setVisible(true);
            setStars(level24, stars);
            continue;
        }
        if (i==24) {
            level25->setVisible(true);
            setStars(level25, stars);
            continue;
        }
        if (i==25) {
            level26->setVisible(true);
            setStars(level26, stars);
            continue;
        }
        if (i==26) {
            level27->setVisible(true);
            setStars(level27, stars);
            continue;
        }
        if (i==27) {
            level28->setVisible(true);
            setStars(level28, stars);
            continue;
        }
        if (i==28) {
            level29->setVisible(true);
            setStars(level29, stars);
            continue;
        }
        if (i==29) {
            level30->setVisible(true);
            setStars(level30, stars);
            continue;
        }
        if (i==30) {
            level31->setVisible(true);
            setStars(level31, stars);
            continue;
        }
        if (i==31) {
            level32->setVisible(true);
            setStars(level32, stars);
            continue;
        }
        if (i==32) {
            level33->setVisible(true);
            setStars(level33, stars);
            continue;
        }
        if (i==33) {
            level34->setVisible(true);
            setStars(level34, stars);
            continue;
        }
        if (i==34) {
            level35->setVisible(true);
            setStars(level35, stars);
            continue;
        }
        if (i==35) {
            level34->setVisible(true);
            setStars(level34, stars);
            continue;
        }
        if (i==36) {
            level37->setVisible(true);
            setStars(level37, stars);
            continue;
        }
        if (i==37) {
            level38->setVisible(true);
            setStars(level38, stars);
            continue;
        }
        if (i==38) {
            level39->setVisible(true);
            setStars(level39, stars);
            continue;
        }
        if (i==39) {
            level40->setVisible(true);
            setStars(level40, stars);
            continue;
        }
        if (i==40) {
            level41->setVisible(true);
            setStars(level41, stars);
            continue;
        }
        if (i==41) {
            level42->setVisible(true);
            setStars(level42, stars);
            continue;
        }
        if (i==42) {
            level43->setVisible(true);
            setStars(level43, stars);
            continue;
        }
        if (i==43) {
            level44->setVisible(true);
            setStars(level44, stars);
            continue;
        }
        if (i==44) {
            level45->setVisible(true);
            setStars(level45, stars);
            continue;
        }
        if (i==45) {
            level46->setVisible(true);
            setStars(level46, stars);
            continue;
        }
        if (i==46) {
            level47->setVisible(true);
            setStars(level47, stars);
            continue;
        }
        if (i==47) {
            level48->setVisible(true);
            setStars(level48, stars);
            continue;
        }
        if (i==48) {
            level49->setVisible(true);
            setStars(level49, stars);
            continue;
        }
        if (i==49) {
            level50->setVisible(true);
            setStars(level50, stars);
            continue;
        }
        if (i==50) {
            level51->setVisible(true);
            setStars(level51, stars);
            continue;
        }
        if (i==51) {
            level52->setVisible(true);
            setStars(level52, stars);
            continue;
        }
        if (i==52) {
            level53->setVisible(true);
            setStars(level53, stars);
            continue;
        }
        if (i==53) {
            level54->setVisible(true);
            setStars(level54, stars);
            continue;
        }
        if (i==54) {
            level55->setVisible(true);
            setStars(level55, stars);
            continue;
        }
        if (i==55) {
            level56->setVisible(true);
            setStars(level56, stars);
            continue;
        }
        if (i==56) {
            level57->setVisible(true);
            setStars(level57, stars);
            continue;
        }
        if (i==57) {
            level58->setVisible(true);
            setStars(level58, stars);
            continue;
        }
        if (i==58) {
            level59->setVisible(true);
            setStars(level59, stars);
            continue;
        }
        if (i==59) {
            level60->setVisible(true);
            setStars(level60, stars);
            continue;
        }
        if (i==60) {
            level61->setVisible(true);
            setStars(level61, stars);
            continue;
        }
        if (i==61) {
            level62->setVisible(true);
            setStars(level62, stars);
            continue;
        }
        if (i==62) {
            level63->setVisible(true);
            setStars(level63, stars);
            continue;
        }
        if (i==63) {
            level64->setVisible(true);
            setStars(level64, stars);
            continue;
        }
        if (i==64) {
            level65->setVisible(true);
            setStars(level65, stars);
            continue;
        }
        if (i==65) {
            level66->setVisible(true);
            setStars(level66, stars);
            continue;
        }
        if (i==66) {
            level67->setVisible(true);
            setStars(level67, stars);
            continue;
        }
        if (i==67) {
            level68->setVisible(true);
            setStars(level68, stars);
            continue;
        }
        if (i==68) {
            level69->setVisible(true);
            setStars(level69, stars);
            continue;
        }
        if (i==69) {
            level70->setVisible(true);
            setStars(level70, stars);
            continue;
        }
        if (i==70) {
            level71->setVisible(true);
            setStars(level71, stars);
            continue;
        }
        if (i==71) {
            level72->setVisible(true);
            setStars(level72, stars);
            continue;
        }
        if (i==72) {
            level73->setVisible(true);
            setStars(level73, stars);
            continue;
        }
        if (i==73) {
            level74->setVisible(true);
            setStars(level74, stars);
            continue;
        }
        if (i==74) {
            level75->setVisible(true);
            setStars(level75, stars);
            continue;
        }
        if (i==75) {
            level76->setVisible(true);
            setStars(level76, stars);
            continue;
        }
        if (i==76) {
            level77->setVisible(true);
            setStars(level77, stars);
            continue;
        }
        if (i==77) {
            level78->setVisible(true);
            setStars(level78, stars);
            continue;
        }
        if (i==78) {
            level79->setVisible(true);
            setStars(level79, stars);
            continue;
        }
        if (i==79) {
            level80->setVisible(true);
            setStars(level80, stars);
            continue;
        }
        if (i==80) {
            level81->setVisible(true);
            setStars(level81, stars);
            continue;
        }
        if (i==81) {
            level82->setVisible(true);
            setStars(level82, stars);
            continue;
        }
        if (i==82) {
            level83->setVisible(true);
            setStars(level83, stars);
            continue;
        }
        if (i==83) {
            level84->setVisible(true);
            setStars(level84, stars);
            continue;
        }
        if (i==84) {
            level85->setVisible(true);
            setStars(level85, stars);
            continue;
        }
        if (i==85) {
            level86->setVisible(true);
            setStars(level86, stars);
            continue;
        }
        if (i==86) {
            level87->setVisible(true);
            setStars(level87, stars);
            continue;
        }
        if (i==87) {
            level88->setVisible(true);
            setStars(level88, stars);
            continue;
        }
        if (i==88) {
            level89->setVisible(true);
            setStars(level89, stars);
            continue;
        }
        if (i==89) {
            level90->setVisible(true);
            setStars(level90, stars);
            continue;
        }
        if (i==90) {
            level91->setVisible(true);
            setStars(level91, stars);
            continue;
        }
        if (i==91) {
            level92->setVisible(true);
            setStars(level92, stars);
            continue;
        }
        if (i==92) {
            level93->setVisible(true);
            setStars(level93, stars);
            continue;
        }
        if (i==93) {
            level94->setVisible(true);
            setStars(level94, stars);
            continue;
        }
        if (i==94) {
            level95->setVisible(true);
            setStars(level95, stars);
            continue;
        }
        if (i==95) {
            level96->setVisible(true);
            setStars(level96, stars);
            continue;
        }
        if (i==96) {
            level97->setVisible(true);
            setStars(level97, stars);
            continue;
        }
        if (i==97) {
            level98->setVisible(true);
            setStars(level98, stars);
            continue;
        }
        if (i==98) {
            level99->setVisible(true);
            setStars(level99, stars);
            continue;
        }
        if (i==99) {
            level100->setVisible(true);
            setStars(level100, stars);
            continue;
        }
        if (i==100) {
            level101->setVisible(true);
            setStars(level101, stars);
            continue;
        }
        if (i==101) {
            level102->setVisible(true);
            setStars(level102, stars);
            continue;
        }
        if (i==102) {
            level103->setVisible(true);
            setStars(level103, stars);
            continue;
        }
        if (i==103) {
            level104->setVisible(true);
            setStars(level104, stars);
            continue;
        }
        if (i==104) {
            level105->setVisible(true);
            setStars(level105, stars);
            continue;
        }
        if (i==105) {
            level106->setVisible(true);
            setStars(level106, stars);
            continue;
        }
        if (i==106) {
            level107->setVisible(true);
            setStars(level107, stars);
            continue;
        }
        if (i==107) {
            level108->setVisible(true);
            setStars(level108, stars);
            continue;
        }
        if (i==108) {
            level109->setVisible(true);
            setStars(level109, stars);
            continue;
        }
        if (i==109) {
            level110->setVisible(true);
            setStars(level110, stars);
            continue;
        }
        if (i==110) {
            level111->setVisible(true);
            setStars(level111, stars);
            continue;
        }
        if (i==111) {
            level112->setVisible(true);
            setStars(level112, stars);
            continue;
        }
        if (i==112) {
            level113->setVisible(true);
            setStars(level113, stars);
            continue;
        }
        if (i==113) {
            level114->setVisible(true);
            setStars(level114, stars);
            continue;
        }
        if (i==114) {
            level115->setVisible(true);
            setStars(level115, stars);
            continue;
        }
        if (i==115) {
            level116->setVisible(true);
            setStars(level116, stars);
            continue;
        }
        if (i==116) {
            level117->setVisible(true);
            setStars(level117, stars);
            continue;
        }
        if (i==117) {
            level118->setVisible(true);
            setStars(level118, stars);
            continue;
        }
        if (i==118) {
            level119->setVisible(true);
            setStars(level119, stars);
            continue;
        }
        if (i==119) {
            level120->setVisible(true);
            setStars(level120, stars);
            continue;
        }


    }
}

void Process::setStars(cocos2d::CCSprite *l, int s)
{
    switch (s) {
        case 0:
            if (l->getChildByTag(1)->isVisible()) {
                l->getChildByTag(1)->setVisible(false);
            }
            if (l->getChildByTag(2)->isVisible()) {
                l->getChildByTag(2)->setVisible(false);
            }
            if (l->getChildByTag(3)->isVisible()) {
                l->getChildByTag(3)->setVisible(false);
            }
            break;
        case 1:
            if (!l->getChildByTag(1)->isVisible()) {
                l->getChildByTag(1)->setVisible(true);
            }
            if (l->getChildByTag(2)->isVisible()) {
                l->getChildByTag(2)->setVisible(false);
            }
            if (l->getChildByTag(3)->isVisible()) {
                l->getChildByTag(3)->setVisible(false);
            }
            break;
        case 2:
            if (!l->getChildByTag(1)->isVisible()) {
                l->getChildByTag(1)->setVisible(true);
            }
            if (!l->getChildByTag(2)->isVisible()) {
                l->getChildByTag(2)->setVisible(true);
            }
            if (l->getChildByTag(3)->isVisible()) {
                l->getChildByTag(3)->setVisible(false);
            }
            break;
        case 3:
            if (!l->getChildByTag(1)->isVisible()) {
                l->getChildByTag(1)->setVisible(true);
            }
            if (!l->getChildByTag(2)->isVisible()) {
                l->getChildByTag(2)->setVisible(true);
            }
            if (!l->getChildByTag(3)->isVisible()) {
                l->getChildByTag(3)->setVisible(true);
            }
            break;
        default:
            break;
    }

}

bool Process::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_ri", CCSprite*, this->level_ri);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_west", CCSprite*, this->level_west);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_tale", CCSprite*, this->level_tale);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_cn", CCSprite*, this->level_cn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_evil", CCSprite*, this->level_evil);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level1", CCSprite*, this->level1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level2", CCSprite*, this->level2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level3", CCSprite*, this->level3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level4", CCSprite*, this->level4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level5", CCSprite*, this->level5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level6", CCSprite*, this->level6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level7", CCSprite*, this->level7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level8", CCSprite*, this->level8);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level9", CCSprite*, this->level9);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level10", CCSprite*, this->level10);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level11", CCSprite*, this->level11);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level12", CCSprite*, this->level12);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level13", CCSprite*, this->level13);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level14", CCSprite*, this->level14);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level15", CCSprite*, this->level15);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level16", CCSprite*, this->level16);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level17", CCSprite*, this->level17);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level18", CCSprite*, this->level18);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level19", CCSprite*, this->level19);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level20", CCSprite*, this->level20);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level21", CCSprite*, this->level21);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level22", CCSprite*, this->level22);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level23", CCSprite*, this->level23);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level24", CCSprite*, this->level24);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level25", CCSprite*, this->level25);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level26", CCSprite*, this->level26);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level27", CCSprite*, this->level27);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level28", CCSprite*, this->level28);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level29", CCSprite*, this->level29);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level30", CCSprite*, this->level30);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level31", CCSprite*, this->level31);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level32", CCSprite*, this->level32);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level33", CCSprite*, this->level33);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level34", CCSprite*, this->level34);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level35", CCSprite*, this->level35);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level36", CCSprite*, this->level36);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level37", CCSprite*, this->level37);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level38", CCSprite*, this->level38);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level39", CCSprite*, this->level39);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level40", CCSprite*, this->level40);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level41", CCSprite*, this->level41);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level42", CCSprite*, this->level42);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level43", CCSprite*, this->level43);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level44", CCSprite*, this->level44);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level45", CCSprite*, this->level45);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level46", CCSprite*, this->level46);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level47", CCSprite*, this->level47);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level48", CCSprite*, this->level48);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level49", CCSprite*, this->level49);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level50", CCSprite*, this->level50);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level51", CCSprite*, this->level51);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level52", CCSprite*, this->level52);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level53", CCSprite*, this->level53);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level54", CCSprite*, this->level54);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level55", CCSprite*, this->level55);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level56", CCSprite*, this->level56);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level57", CCSprite*, this->level57);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level58", CCSprite*, this->level58);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level59", CCSprite*, this->level59);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level60", CCSprite*, this->level60);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level61", CCSprite*, this->level61);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level62", CCSprite*, this->level62);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level63", CCSprite*, this->level63);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level64", CCSprite*, this->level64);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level65", CCSprite*, this->level65);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level66", CCSprite*, this->level66);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level67", CCSprite*, this->level67);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level68", CCSprite*, this->level68);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level69", CCSprite*, this->level69);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level70", CCSprite*, this->level70);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level71", CCSprite*, this->level71);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level72", CCSprite*, this->level72);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level73", CCSprite*, this->level73);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level74", CCSprite*, this->level74);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level75", CCSprite*, this->level75);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level76", CCSprite*, this->level76);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level77", CCSprite*, this->level77);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level78", CCSprite*, this->level78);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level79", CCSprite*, this->level79);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level80", CCSprite*, this->level80);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level81", CCSprite*, this->level81);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level82", CCSprite*, this->level82);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level83", CCSprite*, this->level83);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level84", CCSprite*, this->level84);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level85", CCSprite*, this->level85);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level86", CCSprite*, this->level86);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level87", CCSprite*, this->level87);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level88", CCSprite*, this->level88);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level89", CCSprite*, this->level89);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level90", CCSprite*, this->level90);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level91", CCSprite*, this->level91);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level92", CCSprite*, this->level92);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level93", CCSprite*, this->level93);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level94", CCSprite*, this->level94);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level95", CCSprite*, this->level95);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level96", CCSprite*, this->level96);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level97", CCSprite*, this->level97);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level98", CCSprite*, this->level98);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level99", CCSprite*, this->level99);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level100", CCSprite*, this->level100);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level101", CCSprite*, this->level101);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level102", CCSprite*, this->level102);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level103", CCSprite*, this->level103);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level104", CCSprite*, this->level104);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level105", CCSprite*, this->level105);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level106", CCSprite*, this->level106);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level107", CCSprite*, this->level107);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level108", CCSprite*, this->level108);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level109", CCSprite*, this->level109);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level110", CCSprite*, this->level110);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level111", CCSprite*, this->level111);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level112", CCSprite*, this->level112);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level113", CCSprite*, this->level113);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level114", CCSprite*, this->level114);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level115", CCSprite*, this->level115);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level116", CCSprite*, this->level116);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level117", CCSprite*, this->level117);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level118", CCSprite*, this->level118);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level119", CCSprite*, this->level119);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level120", CCSprite*, this->level120);
    
    return false;
}

bool Process::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 32, 16);
    CCRect* pGameTextureRect = new CCRect(410, 280, 32, 16);
    CCRect* pLevel1Rect = new CCRect(72, 186.5, 48, 38.4);
    CCRect* pLevel2Rect = new CCRect(130.5, 186.5, 48, 38.4);
    CCRect* pLevel3Rect = new CCRect(189, 186.5, 48, 38.4);
    CCRect* pLevel4Rect = new CCRect(247.5, 186.5, 48, 38.4);
    CCRect* pLevel5Rect = new CCRect(306, 186.5, 48, 38.4);
    CCRect* pLevel6Rect = new CCRect(364.5, 186.5, 48, 38.4);
    CCRect* pLevel7Rect = new CCRect(72, 132, 48, 38.4);
    CCRect* pLevel8Rect = new CCRect(130.5, 132, 48, 38.4);
    CCRect* pLevel9Rect = new CCRect(189, 132, 48, 38.4);
    CCRect* pLevel10Rect = new CCRect(247.5, 132, 48, 38.4);
    CCRect* pLevel11Rect = new CCRect(306, 132, 48, 38.4);
    CCRect* pLevel12Rect = new CCRect(364.5, 132, 48, 38.4);
    CCRect* pLevel13Rect = new CCRect(72, 77, 48, 38.4);
    CCRect* pLevel14Rect = new CCRect(130.5, 77, 48, 38.4);
    CCRect* pLevel15Rect = new CCRect(189, 77, 48, 38.4);
    CCRect* pLevel16Rect = new CCRect(247.5, 77, 48, 38.4);
    CCRect* pLevel17Rect = new CCRect(306, 77, 48, 38.4);
    CCRect* pLevel18Rect = new CCRect(364.5, 77, 48, 38.4);
    CCRect* pLevel19Rect = new CCRect(72, 21, 48, 38.4);
    CCRect* pLevel20Rect = new CCRect(130.5, 21, 48, 38.4);
    CCRect* pLevel21Rect = new CCRect(189, 21, 48, 38.4);
    CCRect* pLevel22Rect = new CCRect(247.5, 21, 48, 38.4);
    CCRect* pLevel23Rect = new CCRect(306, 21, 48, 38.4);
    CCRect* pLevel24Rect = new CCRect(364.5, 21, 48, 38.4);
    CCRect* pLeftDirectionRect = new CCRect(0, 112, 50, 40);
    CCRect* pRightDirectionRect = new CCRect(430, 112, 50, 40);
    
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } else if (pRightDirectionRect->containsPoint(location)) {
        if (mapType < 5) {
            CCMoveBy* moveRiBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveWestBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveTaleBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveCnBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveEvilBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            //level_ri->setVisible(false);
            level_ri->runAction(moveRiBy);
            level_west->runAction(moveWestBy);
            level_tale->runAction(moveTaleBy);
            level_cn->runAction(moveCnBy);
            level_evil->runAction(moveEvilBy);
        
            mapType++;
        }
    } else if (pLeftDirectionRect->containsPoint(location)) {
        if (mapType > 1) {
            CCMoveBy* moveRiBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveWestBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveTaleBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveCnBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveEvilBy = CCMoveBy::create(0.5f, ccp(480, 0));
            //level_ri->setVisible(false);
            level_ri->runAction(moveRiBy);
            level_west->runAction(moveWestBy);
            level_tale->runAction(moveTaleBy);
            level_cn->runAction(moveCnBy);
            level_evil->runAction(moveEvilBy);
            
            mapType--;
        }
    } else if (pLevel1Rect->containsPoint(location) and level1->isVisible()) {
        levelNum = 1;
        sendStartRequest();
    } else if (pLevel2Rect->containsPoint(location) and level2->isVisible()) {
        levelNum = 2;
        sendStartRequest();
    } else if (pLevel3Rect->containsPoint(location) and level3->isVisible()) {
        levelNum = 3;
        sendStartRequest();
    } else if (pLevel4Rect->containsPoint(location) and level4->isVisible()) {
        levelNum = 4;
        sendStartRequest();
    } else if (pLevel5Rect->containsPoint(location) and level5->isVisible()) {
        levelNum = 5;
        sendStartRequest();
    } else if (pLevel6Rect->containsPoint(location) and level6->isVisible()) {
        levelNum = 6;
        isMouseGame = true;
        sendStartRequest();
    } else if (pLevel7Rect->containsPoint(location) and level7->isVisible()) {
        levelNum = 7;
        sendStartRequest();
    } else if (pLevel8Rect->containsPoint(location) and level8->isVisible()) {
        levelNum = 8;
        sendStartRequest();
    } else if (pLevel9Rect->containsPoint(location) and level9->isVisible()) {
        levelNum = 9;
        sendStartRequest();
    } else if (pLevel10Rect->containsPoint(location) and level10->isVisible()) {
        levelNum = 10;
        sendStartRequest();
    } else if (pLevel11Rect->containsPoint(location) and level11->isVisible()) {
        levelNum = 11;
        sendStartRequest();
    } else if (pLevel12Rect->containsPoint(location) and level12->isVisible()) {
        levelNum = 12;
        sendStartRequest();
    } else if (pLevel13Rect->containsPoint(location) and level13->isVisible()) {
        levelNum = 13;
        sendStartRequest();
    } else if (pLevel14Rect->containsPoint(location) and level14->isVisible()) {
        levelNum = 14;
        sendStartRequest();
    } else if (pLevel15Rect->containsPoint(location) and level15->isVisible()) {
        levelNum = 15;
        sendStartRequest();
    } else if (pLevel16Rect->containsPoint(location) and level16->isVisible()) {
        levelNum = 16;
        sendStartRequest();
    } else if (pLevel17Rect->containsPoint(location) and level17->isVisible()) {
        levelNum = 17;
        sendStartRequest();
    } else if (pLevel18Rect->containsPoint(location) and level18->isVisible()) {
        levelNum = 18;
        isMouseGame = true;
        sendStartRequest();
    } else if (pLevel19Rect->containsPoint(location) and level19->isVisible()) {
        levelNum = 19;
        sendStartRequest();
    } else if (pLevel20Rect->containsPoint(location) and level20->isVisible()) {
        levelNum = 20;
        sendStartRequest();
    } else if (pLevel21Rect->containsPoint(location) and level21->isVisible()) {
        levelNum = 21;
        sendStartRequest();
    } else if (pLevel22Rect->containsPoint(location) and level22->isVisible()) {
        levelNum = 22;
        sendStartRequest();
    } else if (pLevel23Rect->containsPoint(location) and level23->isVisible()) {
        levelNum = 23;
        sendStartRequest();
    } else if (pLevel24Rect->containsPoint(location) and level24->isVisible()) {
        levelNum = 24;
        sendStartRequest();
    } 
    return true;
}

void Process::sendStartRequest()
{
    char url[255];
    std::string server = STATIC_DATA_STRING("server");
    sprintf(url, "%sbattle/startApi&SID=%s", server.c_str(), Load::sharedSessionId.c_str());
    cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(Process::onStartRequestCompleted));
    request->setTag("Battle Start");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}

void Process::onStartRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    // You can get original request type from: response->request->reqType
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s completed", response->getHttpRequest()->getTag());
    }
    
    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("response code: %d", statusCode);
    
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // dump data
    std::vector<char> *buffer = response->getResponseData();
    const std::string jsonStr(buffer->begin(),buffer->end());
    JsonBox::Value json;
    json.loadFromString(jsonStr);
    
    if (json["data"]["result"].getBoolean()) {

        /* update cp value and remain time*/

        if (isMouseGame) {
            initMouseGame();
        } else {
            initNormalGame();
        }
    }
}

void Process::initNormalGame()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CCScene* pGameScene = NormalGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}

void Process::initMouseGame()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CCScene* pGameScene = MouseGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}
