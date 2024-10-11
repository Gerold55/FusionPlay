-- cube.lua
local angle = 0
local cubeVertices = {
    {-1, -1, -1}, { 1, -1, -1}, { 1,  1, -1}, {-1,  1, -1},  -- Back face
    {-1, -1,  1}, { 1, -1,  1}, { 1,  1,  1}, {-1,  1,  1}   -- Front face
}

local cubeEdges = {
    {1, 2}, {2, 3}, {3, 4}, {4, 1},  -- Back face edges
    {5, 6}, {6, 7}, {7, 8}, {8, 5},  -- Front face edges
    {1, 5}, {2, 6}, {3, 7}, {4, 8}   -- Connecting edges
}

function drawCube()
    local cosAngle = math.cos(angle)
    local sinAngle = math.sin(angle)

    -- Rotate and render each vertex
    for _, edge in ipairs(cubeEdges) do
        local v1 = cubeVertices[edge[1]]
        local v2 = cubeVertices[edge[2]]

        -- Apply rotation transformation around Y-axis
        local x1 = v1[1] * cosAngle - v1[3] * sinAngle
        local z1 = v1[1] * sinAngle + v1[3] * cosAngle
        local x2 = v2[1] * cosAngle - v2[3] * sinAngle
        local z2 = v2[1] * sinAngle + v2[3] * cosAngle

        -- Render the edge (you need to implement `drawLine` in C++)
        drawLine(x1, v1[2], z1, x2, v2[2], z2)
    end

    angle = angle + 0.01  -- Increment the rotation angle
end

function update()
    drawCube()
end
