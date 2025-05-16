---
layout: page
title: felix86 Compatibility List
permalink: /compat/
---

<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <style>
    .tabs { display: flex; gap: 10px; margin-bottom: 10px; }
    .tab { cursor: pointer; padding: 10px; background: lightgray; border-radius: 5px; }
    .tab.active { background: darkgray; }
    .search { margin-bottom: 10px; }
    .game-list { display: flex; flex-wrap: wrap; gap: 10px; }
    .game { border: 1px solid #ccc; padding: 10px; border-radius: 5px; width: 200px; text-align: center; }
    .game img { width: 100%; height: 150px; object-fit: contain; border-radius: 5px; }
    .status { font-weight: bold; }
    .green { color: green; }
    .yellow { color: orange; }
    .red { color: red; }
    .pagination { margin-top: 20px; display: flex; gap: 5px; flex-wrap: wrap; }
    .pagination button { padding: 5px 10px; border: none; background: lightgray; border-radius: 5px; cursor: pointer; }
    .pagination button.active { background: darkgray; color: white; }
  </style>
</head>
<body>
  <div class="tabs">
    <div class="tab active" onclick="filterCategory('all', this)">All</div>
    <div class="tab" onclick="filterCategory('working', this)">Working</div>
    <div class="tab" onclick="filterCategory('partial', this)">Partially Working</div>
    <div class="tab" onclick="filterCategory('not-working', this)">Not Working</div>
  </div>

  <input class="search" type="text" placeholder="Search games..." onkeyup="applyFilters()">

  <div class="game-list" id="games"></div>
  <div class="pagination" id="pagination"></div>

  <div id="all-games" style="display: none">
          
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Volley Pals" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/40">Volley Pals</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/0ce543b7-7395-4425-9e1c-ff7e79f1ae76" alt="Bridge Constructor Portal" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/39">Bridge Constructor Portal</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/6e08c31e-8ea9-493d-b9a2-9edc915bf496" alt="140" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/38">140</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/fcd7216f-3fb4-4d90-ae75-13dc7d44b1db" alt="Death Trash (Demo)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/37">Death Trash (Demo)</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Bzzzt (Demo)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/36">Bzzzt (Demo)</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/dcf8c773-94ac-4a6a-9593-a462fe8cf465" alt="Shogun Showdown: Prologue" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/35">Shogun Showdown: Prologue</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/3f9c73b6-6d6a-4eae-b722-edde2399e2c9" alt="Stardew Valley" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/34">Stardew Valley</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Hotline Miami" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/33">Hotline Miami</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/d05c1827-ccf1-49c1-90ef-dcfe2588f785" alt="Psychonauts" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/32">Psychonauts</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Amnesia: The Dark Descent" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/31">Amnesia: The Dark Descent</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/6e2534b6-6f1f-47d7-989e-e78d4c321ced" alt="Worms W.M.D." width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/30">Worms W.M.D.</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/64a3bdcf-6e3b-446d-87e7-b4cb2d6a4a70" alt="Turok" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/29">Turok</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/54e4f6d1-46e6-413d-815c-b89970ae5654" alt="5D Chess With Multiverse Time Travel" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/28">5D Chess With Multiverse Time Travel</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/e1bb0ad0-5e70-417a-89ff-d2e758924c7c" alt="Undertale" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/27">Undertale</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/859bc9fa-0a37-4083-8e74-cb61d199e89e" alt="Portal" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/26">Portal</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/8d89370b-477f-4d1d-ab41-ab75f4562c1a" alt="Pizza Tower (Windows)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/25">Pizza Tower (Windows)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/a087025a-05a9-4a53-b924-185d62311313" alt="World of Goo 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/24">World of Goo 2</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/f6ce84ae-44e3-4191-9b42-4af3e07666fc" alt="Shovel Knight: Specter of Torment" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/23">Shovel Knight: Specter of Torment</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Terraria" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/22">Terraria</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/2f774381-0efc-4bbe-8374-571cf880e49e" alt="Solitaire (Windows)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/21">Solitaire (Windows)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/c6d4418e-20ee-491f-8262-e3c339a81d36" alt="SuperTux" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/20">SuperTux</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/c1f49fd0-a12a-4584-b5df-089e9e57a7f6" alt="Absolute Drift" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/19">Absolute Drift</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/9344500c-eaf2-494a-bc78-367d4ac078d2" alt="Rogue Legacy" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/18">Rogue Legacy</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="60 Seconds" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/17">60 Seconds</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/f49cdb0e-c0ab-4637-b3e9-a7cf00a31f2f" alt="Baba Is You" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/16">Baba Is You</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Doom 64" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/15">Doom 64</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/e67f8e2b-3343-41d0-9d29-bd18017d6de4" alt="Outlast" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/14">Outlast</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/76aa91d7-3ac1-4a3a-8bb3-79c301d5e790" alt="Cuphead" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/13">Cuphead</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/73df69d9-1a06-46c6-ba75-503366151830" alt="Untitled Goose Game" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/12">Untitled Goose Game</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/57ce4cc1-00d0-4a61-9b1e-6c0c4da6d965" alt="Hotline Miami 2: Wrong Number" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/11">Hotline Miami 2: Wrong Number</a></p><p class="status green">Working</p></div>



  </div>

  <script>
    const allGames = Array.from(document.querySelectorAll('#all-games .game'));
    const gameContainer = document.getElementById('games');
    const pagination = document.getElementById('pagination');
    let filteredGames = allGames;
    let currentPage = 1;
    const gamesPerPage = 9;
    let currentCategory = 'all';

    function filterCategory(category, tabElement) {
      currentCategory = category;
      currentPage = 1;
      document.querySelectorAll('.tab').forEach(tab => tab.classList.remove('active'));
      tabElement.classList.add('active');
      applyFilters();
    }

    function applyFilters() {
      const search = document.querySelector('.search').value.toLowerCase();

      filteredGames = allGames.filter(game => {
        const matchesCategory = currentCategory === 'all' || game.dataset.category === currentCategory;
        const matchesSearch = game.querySelector('p').innerText.toLowerCase().includes(search);
        return matchesCategory && matchesSearch;
      });

      renderGames();
      renderPagination();
    }

    function renderGames() {
      gameContainer.innerHTML = '';
      const start = (currentPage - 1) * gamesPerPage;
      const end = start + gamesPerPage;
      const gamesToShow = filteredGames.slice(start, end);
      gamesToShow.forEach(game => gameContainer.appendChild(game.cloneNode(true)));
    }

    function renderPagination() {
      pagination.innerHTML = '';
      const totalPages = Math.ceil(filteredGames.length / gamesPerPage);
      for (let i = 1; i <= totalPages; i++) {
        const btn = document.createElement('button');
        btn.textContent = i;
        btn.classList.toggle('active', i === currentPage);
        btn.onclick = () => {
          currentPage = i;
          renderGames();
          renderPagination();
        };
        pagination.appendChild(btn);
      }
    }

    window.onload = () => {
      applyFilters();
    };
  </script>
</body>
</html>

Generated from [https://github.com/felix86-emu/compatibility-list](https://github.com/felix86-emu/compatibility-list)
