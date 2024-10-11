-- Update function (called every frame)
function update()
    -- You can add game logic here, such as movement or interactions.
end

-- Render function (called every frame)
function render()
    -- Clear the screen
    glClearColor(0.1, 0.1, 0.1, 1.0)  -- Set the background color (dark gray)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)  -- Clear the color and depth buffers

    -- Draw a cube
    drawCube()  -- Call the C++ function to render the cube
end
