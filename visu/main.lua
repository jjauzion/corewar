------TOOLS

function round(num, dec) --Arrondit num avec une precision de dec
  local mult = 10^(dec or 0)
  return math.floor(num * mult + 0.5) / mult
end

function love.keypressed(k)
   if k == 'escape' then
      love.event.quit()
   end
   if k == 'space' then
       love.event.quit()
   end
end

function get_init_values() -- FIRST PARSING TO GET: arena_s player_name player_com
    line = io.read("*line")
    arena_s = tonumber(string.sub(line, 14, string.len(line)))
    line = io.read("*line")
    nbr_champs = tonumber(string.sub(line, 16, string.len(line)))
    if (nbr_champs > 4) then io.write("nbr champs is too hight! max 4") love.event.quit() end
    for index=1, nbr_champs do
        line = io.read("*line")
        player_name[index] = string.sub(line, 17, string.len(line))
        line = io.read("*line")
        player_com[index] = string.sub(line, 20, string.len(line))
        if (string.len(player_com[index]) > 25) then player_com[index] = string.sub(player_com[index], 0, 13) .. "..." end
        if (string.len(player_name[index]) > 15) then player_name[index] = string.sub(player_name[index], 0, 13) .. "..." end
    end
end

function print_title()
    love.graphics.setFont(font_title)
    love.graphics.print("COREWAR", w_widht / 2, 30)
    local lag_title = font_title:getHeight("COREWAR")
    love.graphics.setFont(font_info)
    love.graphics.setColor(1, 0.5, 0.5, 0.7)
    love.graphics.print("By smortier, jjauzion, theo, simon", w_widht / 2, 30 + lag_title)
    love.graphics.setColor(255, 255, 255)
end

function refresh_players()
    for index=1, nbr_champs do
        love.graphics.setCanvas(canvas_player[index])
        love.graphics.setColor(1, 0, 0)
        love.graphics.clear()
        love.graphics.rectangle('line', 0, 0, canvas_player[index]:getWidth(), canvas_player[index]:getHeight())
        love.graphics.setFont(font_player_name)
        love.graphics.print(player_name[index], 0, 0)
        love.graphics.setFont(font_player_com)
        love.graphics.print(player_com[index], 0 + 3, font_player_name:getHeight())
        love.graphics.setCanvas()
        -- love.graphics.setCanvas(canvas_all_players)
        -- love.graphics.draw(canvas_player[index], index * canvas_player[index]:getWidth() - canvas_player[index]:getWidth(), 0)
    end
    love.graphics.setColor(1, 1, 1)
end

function draw_player()
    love.graphics.setColor(1, 1, 1)
    -- love.graphics.draw(canvas_all_players, 0, w_height - (w_height / 7) - 10)
    -- love.graphic.setCanvas(canvas_all_players)
    for index=1, nbr_champs do
        love.graphics.draw(canvas_player[index], index * canvas_player[index]:getWidth() - canvas_player[index]:getWidth(), w_height - (w_height / 7) - 10)
    end
    -- love.graphic.setCanvas()
    love.graphics.setColor(1, 1, 1)
end

function        refresh_arena()
    love.graphics.setCanvas(canvas_arena)
    love.graphics.clear()
    -- love.graphics.setColor(0, 1, 0.5, 0.4)
    love.graphics.setColor(0, 1, 1, 1)
    love.graphics.rectangle('line', 0, 0, canvas_arena:getWidth(), canvas_arena:getHeight())
    love.graphics.setColor(0, 1, 1, 0.7)
    for y=1, canvas_arena:getHeight(), h_box + 1 do
        for x=1, canvas_arena:getWidth(), w_box + 1 do
            -- io.write("y = " .. y .. " && x = " .. x .. '\n')
            love.graphics.rectangle("line", x, y, w_box, h_box)
        end
    end
    love.graphics.setCanvas()
end

function        draw_arena()
    love.graphics.draw(canvas_arena, 30, w_height / 6)
end

function init_canvas()
    canvas_all_players = love.graphics.newCanvas(w_widht - 10, w_height / 7 - 10) --uselss pour le moment
    canvas_arena = love.graphics.newCanvas(w_widht - 60 - 30, round(w_height  - (w_height / 3), 0))
    for index=0, nbr_champs do
        canvas_player[index] = love.graphics.newCanvas(canvas_all_players:getWidth() / nbr_champs,
                                                        canvas_all_players:getHeight())
    end
end

function init_fonts()
    font_title = love.graphics.newFont("font2.ttf", 60)
    font_info = love.graphics.newFont("font2.ttf", 20)
    --Player canvas font
    font_player_name = love.graphics.newFont("font2.ttf", 30)
    font_player_com = love.graphics.newFont("font2.ttf", 20)
    font_player_data = love.graphics.newFont("font2.ttf", 25)
end

function get_box_size()
    local arena_h = (canvas_arena:getHeight())
    local arena_w = (canvas_arena:getWidth())
    local box_h = (arena_h / 64)
    local box_w = (arena_w / 64)
    return round(box_w, 0), round(box_h, 0)
end

-------MAIN

function        love.load()
    love.window.setMode(2560, 1440, {resizable=false, vsync=false, minwidth=400, minheight=300})
    success = love.window.setFullscreen(true)
    w_widht, w_height = love.graphics.getDimensions()
    io.write(w_widht .. '\n' .. w_height .. '\n')
    player_name = {}
    player_com = {}
    canvas_player = {}
    init_fonts()
    get_init_values()
    init_canvas()
    w_box, h_box = get_box_size()
    io.write(arena_s, '\n', w_box,'\n', h_box, '\n')
    start_time = love.timer.getTime()
    -- love.graphics.setBackgroundColor(255, 200, 200)
    -- love.timer.sleep(6)
    -- line = io.read("*line")
end

function        love.update()

end

function        love.draw()
    print_title()
    love.graphics.print('Press Escape to Leave', 10, 10)
    love.graphics.print("Current FPS: "..tostring(love.timer.getFPS( )), 10, 30)
    love.graphics.print("Time since begin : " .. round(love.timer.getTime() - start_time, 0) .. " seconds", 10, 70)
    -- love.graphics.print(round(love.timer.getTime() - start_time, 0), 10, 70)
    --DRAW LES DEUX RECTANGLES
    love.graphics.setColor(1, 1, 1)
    refresh_arena()
    refresh_players()
    draw_arena()
    draw_player()
    -- love.graphics.line(w_widht / 2 , w_height / 2, w_widht / 2, w_height)
end
