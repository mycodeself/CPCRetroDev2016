// #include "bat.h"

// const AnimationFrame _bat_frames[3] = {
//   // sprite, width bytes, height bytes, time, look
//   { sprite_bat0, SPRITE_BAT0_W, SPRITE_BAT0_H, 3, as_left },
//   { sprite_bat1, SPRITE_BAT1_W, SPRITE_BAT1_H, 3, as_left },
//   { sprite_bat2, SPRITE_BAT2_W, SPRITE_BAT2_H, 3, as_left }
// };

// AnimationFrame* const _bat_anim_fly[3] = { &_bat_frames[0], &_bat_frames[1], &_bat_frames[2] };

// const Animation _bat_animation = { _bat_anim_fly, 0, 3, as_play, 0, as_left };

// void updateBats(Bat* bat)
// {
//   u8 i = 0;
//   u8 r = cpct_rand();  
//   AnimationFrame* frame;
  
//   for(;i != 3;i++)
//   {
//     updateAnimation(bat->anim);
//     frame = bat->anim->frames[bat->anim->frame_idx];
//     bat->db.body.w = frame->w;
//     bat->db.body.h = frame->h;
    
//     bat->db.lastx = bat->db.body.x;
//     bat->db.lasty = bat->db.body.y;
//     bat->db.vel.x = 0;
//     bat->db.vel.y = 0;
    
//     if(r > 120)
//       if(bat->anim->side == as_left)
//         bat->db.vel.x -= 1;
//       else
//         bat->db.vel.x += 1;
//     else if(r > 60 && bat->db.body.y < 130)
//       bat->db.vel.y += 1;
//     else if(bat->db.body.y > 100)
//       bat->db.vel.y -=  1;

//     bat->db.body.x += bat->db.vel.x;
//     bat->db.body.y += bat->db.vel.y;
    
//     if(bat->db.body.x <= 0){
//       bat->anim->side = as_right;
//     }else if((bat->db.body.x + bat->db.body.w) >= SCREEN_BYTES_WIDTH)
//     {
//       bat->anim->side = as_left;
//     }
//     ++bat;
//   }
// }