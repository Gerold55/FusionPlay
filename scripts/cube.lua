-- cube.lua

-- Function to draw a cube
function drawCube()
    -- Set up vertices for a cube
    local vertices = {
        -0.5, -0.5, -0.5,  -- 0: Bottom-left-back
         0.5, -0.5, -0.5,  -- 1: Bottom-right-back
         0.5,  0.5, -0.5,  -- 2: Top-right-back
        -0.5,  0.5, -0.5,  -- 3: Top-left-back
        -0.5, -0.5,  0.5,  -- 4: Bottom-left-front
         0.5, -0.5,  0.5,  -- 5: Bottom-right-front
         0.5,  0.5,  0.5,  -- 6: Top-right-front
        -0.5,  0.5,  0.5   -- 7: Top-left-front
    }

    -- Set up the indices for the cube's faces
    local indices = {
        0, 1, 2, 2, 3, 0,  -- Back face
        4, 5, 6, 6, 7, 4,  -- Front face
        0, 4, 5, 5, 1, 0,  -- Bottom face
        3, 7, 6, 6, 2, 3,  -- Top face
        0, 3, 7, 7, 4, 0,  -- Left face
        1, 5, 6, 6, 2, 1   -- Right face
    }

    -- Bind your vertex array and buffer
    glBindVertexArray(vao)  -- Make sure you have the VAO created in C++
    
    -- Upload vertex data to the buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo) -- Make sure you have the VBO created in C++
    glBufferData(GL_ARRAY_BUFFER, vertices, GL_STATIC_DRAW)

    -- Define vertex attribute pointers (ensure you set up your shader to accept this)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nil)
    glEnableVertexAttribArray(0)

    -- Draw the cube
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo) -- Make sure you have the EBO created in C++
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices, GL_STATIC_DRAW)
    glDrawElements(GL_TRIANGLES, #indices, GL_UNSIGNED_INT, nil)

    glBindVertexArray(0) -- Unbind the VAO
end
