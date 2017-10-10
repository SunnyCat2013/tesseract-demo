//
//  main.cpp
//  tesseract-test
//
//  Created by cslzy on 8/31/17.
//  Copyright © 2017 CY. All rights reserved.
//

#include <tesseract/baseapi.h>
#include <tesseract/strngs.h>
#include <leptonica/allheaders.h>
#include <iostream>

using namespace std;
const char* inputImage = "/Users/cslzy/jd/picture-recognition/test/register.jpg";
int main(int argc, const char * argv[]) {
    
    char *outText;
    
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with simple Chinese character, without specifying tessdata path
    if (api->Init(NULL, "chi_sim")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    
    // Open input image with leptonica library
    Pix *image = pixRead(inputImage);
    
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);
    
    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);
    
    return 0;
}
