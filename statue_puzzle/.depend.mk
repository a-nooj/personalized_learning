map.o: map.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h \
 map.h Square.h Unit.h drawConstants.h drawFunctions.h
Square.o: Square.cc Square.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h drawFunctions.h drawConstants.h
towerDefense.o: towerDefense.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h Unit.h Square.h drawConstants.h drawFunctions.h map.h \
 constructionBox.h button.h
Unit.o: Unit.cc Unit.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h Square.h drawConstants.h drawFunctions.h
drawFunctions.o: drawFunctions.cc drawFunctions.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h drawConstants.h Square.h
button.o: button.cc button.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h drawConstants.h Square.h drawFunctions.h
constructionBox.o: constructionBox.cc cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h constructionBox.h drawConstants.h \
 Square.h drawFunctions.h button.h
drawConstants.o: drawConstants.cc
