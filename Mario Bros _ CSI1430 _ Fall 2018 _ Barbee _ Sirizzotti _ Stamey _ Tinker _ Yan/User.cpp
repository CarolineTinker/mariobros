#include "User.h"

void drawFromFile(char fileName[], SDL_Plotter& g){
    //circle
    circle sph;
    int rad;
    point cent;

    //rectangle
    rectangle r;
    point a, b;

    //both
    ifstream file(fileName);
    color clr;
    int INIT;

    if(!file){
        cout << "Error File Not Open" << endl;
    }

    while(file >> INIT){
        //draw circle
        if(INIT == 0){
            file >> rad >> cent.x >> cent.y >> clr.R >> clr.G >> clr.B;
            sph.setRadius(rad);
            sph.setCenter(cent);
            sph.setColor(clr);
            sph.draw(g);

        }
        //draw rectangle
        else if(INIT == 1){
            file >> a.x >> a.y >> b.x >> b.y >> clr.R >> clr.G >> clr.B;
            r.setP1(a);
            r.setP2(b);
            r.setColor(clr);
            r.draw(g);

        }
    }
    file.close();
}


void drawCIRC(char fileName[], SDL_Plotter& g){
    ifstream file(fileName);
    circle sph;
    int r;
    point cent;
    color clr;
    string line;

    if(!file){
        cout << "Error File Not Open" << endl;
    }
    while(file >> r >> cent.x >> cent.y >> clr.R >> clr.G >> clr.B){
        sph.setRadius(r);
        sph.setCenter(cent);
        sph.setColor(clr);
        sph.draw(g);
    }
    file.close();
}

void drawRECT(char fileName[], SDL_Plotter& g){
    ifstream file(fileName);
    rectangle r;
    point a, b;
    color clr;

    if(!file){
        cout << "Error File Not Open" << endl;
    }
    while(file >> a.x >> b.x >> a.y >> b.y >> clr.R >> clr.G >> clr.B){
        r.setP1(a);
        r.setP2(b);
        r.setColor(clr);
        r.draw(g);
    }
    file.close();
}

void draw(char fileName[],SDL_Plotter& g,point p){
    ifstream file(fileName);
    char value;

    if(!file){
        cout << "Error File Not Open" << endl;
    }
    int row, col;
    file >> row >> col;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            file >> value;
            if(value == '1') {
                    g.plotPixel(p.x + c, p.y + r,255,255,255);
            }
            if(value == '2') {
                    g.plotPixel(p.x + c, p.y + r,0,0,0);
            }
        }
    }

    file.close();

}

/* o and w
235 245 100 150 250 250 250
222 232 100 150 250 250 250
209 219 100 150 250 250 250
211 235 140 150 250 250 250
196 206 100 150 250 250 250
176 186 100 150 250 250 250
176 206 100 110 250 250 250
176 206 140 150 250 250 250

283 467 536 539
275 475 532 536
267 483 528 532
261 489 524 528
255 495 520 524
249 501 516 520
244 506 512 516
240 510 508 512
236 514 504 508
232 518 500 504
229 521 496 500
225 525 492 496
221 529 488 492
218 532 484 488
215 535 480 484
213 537 476 480
211 539 472 476
209 541 468 472
207 543 464 468
205 545 460 464
203 547 456 460
202	548	452	456
200	550	448	452
199	551	444	448
197	553	440	444
196	554	436	440
196	554	432	436
195	555	428	432
194	556	424	428
193	557	420	424
193	557	416	420
192	558	412	416
192	558	408	412
191	559	404	408
191	559	400	404
191	559	396	400
190	560	392	396
190	560	388	392
190	560	384	388
190	560	380	384
190	560	384	388

191	559	380	384
191	559	376	380
191	559	372	376
192	558	368	372
192	558	364	368
193	557	360	364
193	557	356	360
194	556	352	356
195	555	348	352
196	554	344	348
196	554	340	344
197	553	336	340
199	551	332	336
200	550	328	332
202	548	324	328
203 547 320 324
205 545 316 320
207 543 312 316
209 541 308 312
211 539 304 308
213 537 300 304
215 535 296 300
218 532 292 296
221 529 288 292
225 525 284 288
229 521 280 284
232 518 276 280
236 514 272 276
240 510 268 272
244 506 264 268
249 501 260 264
255 495 254 260
261 489 250 254
267 483 246 250
275 475 242 246
283 467 238 242
292 458 234 238
302 448 230 234
314 436 226 230 0 0 0
329 421 222 226
*/
