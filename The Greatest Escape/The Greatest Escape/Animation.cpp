#include "Animation.h"

//constructor
Animation::Animation()
{
    std::cout << "Animator ready" << std::endl;
}

sf::IntRect Animation::animate(sf::Texture t_texture, int t_numOfFrames, int t_frameWidth, int t_frameHeight, int t_cols, int t_rows)
{
    totalElapsed++;

    if (totalElapsed >22)
    {
        totalElapsed = 0;
        animationFrame++;
        if (animationFrame > t_numOfFrames) // 12 sprites total
        {
            animationFrame = 0;
        }
    }
    int col = animationFrame % t_cols; // 2 columns of sprites
    int row = animationFrame / t_cols; // 6 rows of sprites

    rectSourceSprite.height = t_frameHeight;  // height / width is gotten with the formula :: totalImageWidth / columns = width and  totalImageHeight / rows = height
    rectSourceSprite.width = t_frameWidth; 
    rectSourceSprite.left = col * rectSourceSprite.width;
    rectSourceSprite.top = row * rectSourceSprite.height;
    
	return rectSourceSprite;
}

