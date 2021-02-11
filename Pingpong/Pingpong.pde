int w = 200; 
int h = 150;
int x = int(random(15, w-15)); 
int y = int(random(5, h-5));
int speedx = 1; 
int speedy = 1;
int score = 0;
boolean game_status = true;

void setup() {
  size(200,150);
  smooth();
}
 
void draw() {
  if(score<=0){
    background(255, 255, 255);
  }else if (score>10 && score<20){
     background(255, 0, 255);
     speedx = 2;
     speedy = 2;
  }else if (score>20 && score<40){
    background(0, 0, 255);
     speedx = 4;
     speedy = 4;
  }else{
      background(0, 0, 55);
     speedx = 6;
     speedy = 6;
  }
   
  x = x + speedx;
  y = y + speedy;
 
  if ((x > width-15) || (x < 15)) {
    speedx = speedx * -1;
    if (x < 15) {
      score += 1;
    }
  }
   
  if ((y > height-5) || (y < 5))  {
    speedy = speedy * -1;
  }
   
  if ((x == 15) && ((mouseY > y+5) || (mouseY+20 < y-5))) {
    if (game_status == true){
      speedx = 0;
      speedy = 0;
      text("Game Over",70,50,80,20);
      text("Press Q to",70,70,80,20);
      text("NEW GAME",70,90,80,20);
     // game_status = false;
    }
  }
  
  if(keyPressed){
    if(key == 'Q' || key == 'q'){
         speedx = 1;
         speedy = 1;
         x = int(random(15, w-15)); 
         y = int(random(5, h-5));
    }
  }
  
  fill(175,175,175);
  ellipse(x,y,10,10);
  rect(190,y-10,10,20);
   
  if (mouseY < height-20) {
    rect(0, mouseY, 10,20);
  }
  else{
    rect(0, height-20, 10, 20);
  }
 
  text("score: " + score, 75, 10);
}
