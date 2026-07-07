---
layout: page
title: felix86 Compatibility List
permalink: /compat/
---

<div class="compat-container">
  <style>
    :root {
      --bg-color: #f8f9fa;
      --card-bg: #ffffff;
      --text-main: #333333;
      --text-muted: #666666;
      --status-working: #28a745;
      --status-partial: #ffc107;
      --status-not-working: #dc3545;
      --status-untested: #6c757d;
      --accent-color: #007bff;
      --transition-speed: 0.3s;
    }

    #main.container {
      max-width: 1400px !important;
      width: 95% !important;
    }

    .compat-container {
      font-family: 'Inter', -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif;
      color: var(--text-main);
      max-width: none;
      margin: 0 auto;
      padding: 20px;
    }

    .controls {
      display: flex;
      flex-direction: column;
      gap: 20px;
      margin-bottom: 30px;
      background: var(--card-bg);
      padding: 20px;
      border-radius: 12px;
      box-shadow: 0 4px 6px rgba(0,0,0,0.05);
    }

    .tabs {
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
    }

    .tab {
      cursor: pointer;
      padding: 10px 20px;
      background: #e9ecef;
      border-radius: 30px;
      font-weight: 500;
      transition: all var(--transition-speed);
      border: none;
      font-size: 14px;
    }

    .tab:hover {
      background: #dee2e6;
    }

    .tab.active {
      background: var(--accent-color);
      color: white;
    }

    .search-container {
      position: relative;
      width: 100%;
    }

    .search-input {
      width: 100%;
      max-width: 500px;
      padding: 12px 20px;
      border: 2px solid #e9ecef;
      border-radius: 8px;
      font-size: 16px;
      transition: border-color var(--transition-speed);
      outline: none;
      box-sizing: border-box;
    }

    .search-input:focus {
      border-color: var(--accent-color);
    }

    .game-list {
      display: grid;
      grid-template-columns: repeat(auto-fill, minmax(180px, 1fr));
      gap: 15px;
      margin-bottom: 40px;
    }

    .game-card {
      background: var(--card-bg);
      border-radius: 12px;
      overflow: hidden;
      box-shadow: 0 4px 15px rgba(0,0,0,0.1);
      transition: transform var(--transition-speed), box-shadow var(--transition-speed);
      display: flex;
      flex-direction: column;
    }

    .game-card:hover {
      transform: translateY(-5px);
      box-shadow: 0 8px 25px rgba(0,0,0,0.15);
    }

    .game-image-container {
      position: relative;
      width: 100%;
      padding-top: 56.25%; /* 16:9 Aspect Ratio */
      background: #f0f0f0;
    }

    .game-image {
      position: absolute;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      object-fit: cover;
    }

    .game-image[src*="felix86NoThoughts"] {
      object-fit: contain;
      object-position: center;
    }

    .game-info {
      padding: 12px;
      display: flex;
      flex-direction: column;
      flex-grow: 1;
      gap: 8px;
    }

    .game-title {
      margin: 0;
      font-size: 18px;
      font-weight: 700;
      line-height: 1.4;
    }

    .game-title a {
      color: var(--text-main);
      text-decoration: none;
    }

    .game-title a:hover {
      color: var(--accent-color);
    }

    .status {
      display: inline-block;
      padding: 4px 12px;
      border-radius: 20px;
      font-size: 12px;
      font-weight: 600;
      text-transform: uppercase;
      width: fit-content;
    }

    .status.green { background: #d4edda; color: var(--status-working); }
    .status.yellow { background: #fff3cd; color: #856404; }
    .status.red { background: #f8d7da; color: var(--status-not-working); }
    .status.gray { background: #e2e3e5; color: var(--status-untested); }

    .pagination {
      display: flex;
      justify-content: center;
      gap: 8px;
      margin-top: 40px;
      flex-wrap: wrap;
    }

    .pagination button {
      padding: 8px 16px;
      border: 1px solid #dee2e6;
      background: white;
      border-radius: 6px;
      cursor: pointer;
      transition: all var(--transition-speed);
      font-weight: 500;
    }

    .pagination button:hover {
      background: #f8f9fa;
      border-color: #adb5bd;
    }

    .pagination button.active {
      background: var(--accent-color);
      color: white;
      border-color: var(--accent-color);
    }

    .no-results {
      text-align: center;
      padding: 50px;
      grid-column: 1 / -1;
      color: var(--text-muted);
      font-size: 18px;
    }

    @media (max-width: 600px) {
      .game-list {
        grid-template-columns: 1fr;
      }
      .controls {
        padding: 15px;
      }
    }
  </style>

  <div class="controls">
    <div class="tabs">
      <button class="tab active" onclick="filterCategory('all', this)">All</button>
      <button class="tab" onclick="filterCategory('working', this)">Working</button>
      <button class="tab" onclick="filterCategory('partial', this)">Partial</button>
      <button class="tab" onclick="filterCategory('not-working', this)">Broken</button>
    </div>
    <div class="search-container">
      <input class="search-input" type="text" placeholder="Search games..." onkeyup="applyFilters()">
    </div>
  </div>

  <div class="game-list" id="games"></div>
  <div class="pagination" id="pagination"></div>

  <div id="all-games" style="display: none">
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Umamusume: Pretty Derby" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/143">Umamusume: Pretty Derby</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/142.jpg" alt="Garfield Kart" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/142">Garfield Kart</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/141.jpg" alt="Your Only Move Is Hustle" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/141">Your Only Move Is Hustle</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/140.jpg" alt="Dishonored" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/140">Dishonored</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/139.jpg" alt="SUPERHOT" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/139">SUPERHOT</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/138.jpg" alt="Split/Second" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/138">Split/Second</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/137.jpg" alt="Mina the Hollower" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/137">Mina the Hollower</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/136.jpg" alt="The Elder Scrolls V: Skyrim Special Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/136">The Elder Scrolls V: Skyrim Special Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/135.jpg" alt="Parkitect" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/135">Parkitect</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/134.jpg" alt="God of War (2018)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/134">God of War (2018)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Project Zomboid" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/133">Project Zomboid</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/132.jpg" alt="FlatOut 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/132">FlatOut 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/131.jpg" alt="WeChat" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/131">WeChat</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/130.jpg" alt="Metro Exodus" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/130">Metro Exodus</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/129.jpg" alt="Hytale" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/129">Hytale</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/128.jpg" alt="Unreal Tournament 99" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/128">Unreal Tournament 99</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/127.jpg" alt="Insane 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/127">Insane 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/126.jpg" alt="Getting Over It with Bennett Foddy" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/126">Getting Over It with Bennett Foddy</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Heroic Games Launcher" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/125">Heroic Games Launcher</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/124.jpg" alt="Genshin Impact" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/124">Genshin Impact</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="LEGO Star Wars III: The Clone Wars" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/123">LEGO Star Wars III: The Clone Wars</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="LEGO Indiana Jones: The Original Adventures" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/122">LEGO Indiana Jones: The Original Adventures</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/121.jpg" alt="Deponia 3: Goodbye Deponia" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/121">Deponia 3: Goodbye Deponia</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/120.jpg" alt="Deponia 2: Chaos on Deponia" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/120">Deponia 2: Chaos on Deponia</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/119.jpg" alt="HuniePop" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/119">HuniePop</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Divinity: Original Sin - Enhanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/118">Divinity: Original Sin - Enhanced Edition</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/117.jpg" alt="Firewatch" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/117">Firewatch</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/116.jpg" alt="Northgard" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/116">Northgard</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/115.jpg" alt="Overcooked! 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/115">Overcooked! 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/114.jpg" alt="Sonic Mania" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/114">Sonic Mania</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Shadowrun Returns" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/113">Shadowrun Returns</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/112.jpg" alt="To The Moon" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/112">To The Moon</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/111.jpg" alt="Torchlight II" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/111">Torchlight II</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="RimWorld" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/110">RimWorld</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="EVERSPACE" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/109">EVERSPACE</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/108.jpg" alt="Crypt of the Necrodancer" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/108">Crypt of the Necrodancer</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/107.jpg" alt="Deponia" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/107">Deponia</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/106.jpg" alt="Stellaris" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/106">Stellaris</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="BioShock" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/105">BioShock</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="PEAK" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/104">PEAK</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Garfield Kart" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/103">Garfield Kart</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Batman: Arkham Origins" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/102">Batman: Arkham Origins</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/101.jpg" alt="Scribblenauts Unlimited" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/101">Scribblenauts Unlimited</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/100.jpg" alt="Noita" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/100">Noita</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/99.jpg" alt="Rayman 3: Hoodlum Havoc" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/99">Rayman 3: Hoodlum Havoc</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/98.jpg" alt="STAR WARS™: Knights of the Old Republic" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/98">STAR WARS™: Knights of the Old Republic</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/97.jpg" alt="Inscryption" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/97">Inscryption</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Fallout New Vegas" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/96">Fallout New Vegas</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/95.jpg" alt="Postal 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/95">Postal 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/94.jpg" alt="Kerbal Space Program" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/94">Kerbal Space Program</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/93.jpg" alt="Hades" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/93">Hades</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/92.jpg" alt="Lethal Company" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/92">Lethal Company</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/91.jpg" alt="Touhou 16 - Hidden Star in Four Seasons" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/91">Touhou 16 - Hidden Star in Four Seasons</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/90.jpg" alt="Transport Fever" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/90">Transport Fever</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/89.jpg" alt="Assassin's Creed" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/89">Assassin's Creed</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/88.jpg" alt="DOOM 3" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/88">DOOM 3</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/87.jpg" alt="Hitman: Blood Money" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/87">Hitman: Blood Money</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/86.jpg" alt="Hollow Knight: Silksong" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/86">Hollow Knight: Silksong</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/85.jpg" alt="Thief Gold" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/85">Thief Gold</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Heroes of Might and Magic 3" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/84">Heroes of Might and Magic 3</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/83.jpg" alt="Sleeping Dogs: Definitive Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/83">Sleeping Dogs: Definitive Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/82.jpg" alt="Warhammer 40,000: Rites of War" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/82">Warhammer 40,000: Rites of War</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/81.jpg" alt="Super Meat Boy" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/81">Super Meat Boy</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/80.jpg" alt="RollerCoaster Tycoon: Deluxe" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/80">RollerCoaster Tycoon: Deluxe</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/79.jpg" alt="Counter-Strike: Source" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/79">Counter-Strike: Source</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Far Cry 2: Fortune's Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/78">Far Cry 2: Fortune's Edition</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/77.jpg" alt="Far Cry" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/77">Far Cry</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/76.jpg" alt="Faster Than Light: Advanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/76">Faster Than Light: Advanced Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/75.jpg" alt="Mini Metro" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/75">Mini Metro</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/74.jpg" alt="Fallout 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/74">Fallout 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/73.jpg" alt="Enter The Gungeon" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/73">Enter The Gungeon</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/72.jpg" alt="Trackmania Nations Forever" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/72">Trackmania Nations Forever</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/71.jpg" alt="SOMA" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/71">SOMA</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/70.jpg" alt="SteamWorld Dig 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/70">SteamWorld Dig 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/69.jpg" alt="SteamWorld Dig" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/69">SteamWorld Dig</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/68.jpg" alt="TUNIC" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/68">TUNIC</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/67.jpg" alt="MiSide (Demo)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/67">MiSide (Demo)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/66.jpg" alt="Max Payne 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/66">Max Payne 2</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/65.jpg" alt="Max Payne" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/65">Max Payne</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/64.jpg" alt="FEZ" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/64">FEZ</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/63.jpg" alt="Baldur's Gate II: Enhanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/63">Baldur's Gate II: Enhanced Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/62.jpg" alt="Baldur's Gate: Enhanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/62">Baldur's Gate: Enhanced Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/61.jpg" alt="Dwarf Fortress" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/61">Dwarf Fortress</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/60.jpg" alt="SpongeBob SquarePants: Battle for Bikini Bottom - Rehydrated" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/60">SpongeBob SquarePants: Battle for Bikini Bottom - Rehydrated</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/59.jpg" alt="DOOM (2016)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/59">DOOM (2016)</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/58.jpg" alt="Europa Universalis IV" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/58">Europa Universalis IV</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/57.jpg" alt="Factorio Demo" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/57">Factorio Demo</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/56.jpg" alt="Witcher 3" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/56">Witcher 3</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/55.jpg" alt="Crysis" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/55">Crysis</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/54.jpg" alt="Psychonauts 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/54">Psychonauts 2</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/53.jpg" alt="Witcher 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/53">Witcher 2</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/52.jpg" alt="Among Us" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/52">Among Us</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/51.jpg" alt="Deltarune Demo" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/51">Deltarune Demo</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/50.jpg" alt="Doki Doki Literature Club" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/50">Doki Doki Literature Club</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/49.jpg" alt="2048" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/49">2048</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/48.jpg" alt="Friday Night Funkin' (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/48">Friday Night Funkin' (Windows)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/47.jpg" alt="Sid Meier’s Civilization VI" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/47">Sid Meier’s Civilization VI</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/46.jpg" alt="Hollow Knight" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/46">Hollow Knight</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="A Hat In Time (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/45">A Hat In Time (Windows)</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/44.jpg" alt="Half-Life" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/44">Half-Life</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/43.jpg" alt="Counter Strike" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/43">Counter Strike</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/42.jpg" alt="LIMBO" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/42">LIMBO</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/41.jpg" alt="Portal 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/41">Portal 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/40.jpg" alt="Volley Pals" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/40">Volley Pals</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/39.jpg" alt="Bridge Constructor Portal" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/39">Bridge Constructor Portal</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/38.jpg" alt="140" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/38">140</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/37.jpg" alt="Death Trash (Demo)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/37">Death Trash (Demo)</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/36.jpg" alt="Bzzzt (Demo)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/36">Bzzzt (Demo)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/35.jpg" alt="Shogun Showdown: Prologue" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/35">Shogun Showdown: Prologue</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/34.jpg" alt="Stardew Valley" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/34">Stardew Valley</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/33.jpg" alt="Hotline Miami" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/33">Hotline Miami</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/32.jpg" alt="Psychonauts" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/32">Psychonauts</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Amnesia: The Dark Descent" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/31">Amnesia: The Dark Descent</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/30.jpg" alt="Worms W.M.D." class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/30">Worms W.M.D.</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/29.jpg" alt="Turok" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/29">Turok</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/28.jpg" alt="5D Chess With Multiverse Time Travel" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/28">5D Chess With Multiverse Time Travel</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/27.jpg" alt="Undertale" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/27">Undertale</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/26.jpg" alt="Portal" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/26">Portal</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/25.jpg" alt="Pizza Tower (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/25">Pizza Tower (Windows)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/24.jpg" alt="World of Goo 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/24">World of Goo 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/23.jpg" alt="Shovel Knight: Specter of Torment" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/23">Shovel Knight: Specter of Torment</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/22.jpg" alt="Terraria" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/22">Terraria</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/21.jpg" alt="Solitaire (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/21">Solitaire (Windows)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/20.jpg" alt="SuperTux" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/20">SuperTux</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/19.jpg" alt="Absolute Drift" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/19">Absolute Drift</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/18.jpg" alt="Rogue Legacy" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/18">Rogue Legacy</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/17.jpg" alt="60 Seconds" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/17">60 Seconds</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felix86NoThoughts.png" alt="Doom 64" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/15">Doom 64</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/14.jpg" alt="Outlast" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/14">Outlast</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/13.jpg" alt="Cuphead" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/13">Cuphead</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/12.jpg" alt="Untitled Goose Game" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/12">Untitled Goose Game</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/11.jpg" alt="Hotline Miami 2: Wrong Number" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/11">Hotline Miami 2: Wrong Number</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/10.jpg" alt="The Binding of Isaac: Rebirth" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/10">The Binding of Isaac: Rebirth</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/9.jpg" alt="Papers, Please" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/9">Papers, Please</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/8.jpg" alt="Don't Starve" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/8">Don't Starve</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/7.jpg" alt="Dimension Tripper Neptune: TOP NEP" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/7">Dimension Tripper Neptune: TOP NEP</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/6.jpg" alt="World of Goo" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/6">World of Goo</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/5.jpg" alt="Celeste" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/5">Celeste</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/4.jpg" alt="openarena" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/4">openarena</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/3.jpg" alt="SuperTuxKart" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/3">SuperTuxKart</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/2.jpg" alt="VVVVVV" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/2">VVVVVV</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/compatibility/1.jpg" alt="Balatro" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/1">Balatro</a></h3>
    <span class="status green">Working</span>
  </div>
</div>

  </div>

  <script>
    const allGames = Array.from(document.querySelectorAll('#all-games .game-card'));
    const gameContainer = document.getElementById('games');
    const paginationContainer = document.getElementById('pagination');
    
    let filteredGames = [...allGames];
    let currentPage = 1;
    const gamesPerPage = 12;
    let currentCategory = 'all';

    function filterCategory(category, tabElement) {
      currentCategory = category;
      currentPage = 1;
      
      document.querySelectorAll('.tab').forEach(tab => tab.classList.remove('active'));
      if (tabElement) tabElement.classList.add('active');
      
      applyFilters();
    }

    function applyFilters() {
      const searchInput = document.querySelector('.search-input');
      const searchTerm = searchInput ? searchInput.value.toLowerCase().trim() : '';

      filteredGames = allGames.filter(game => {
        const matchesCategory = currentCategory === 'all' || game.dataset.category === currentCategory;
        const title = game.querySelector('.game-title').innerText.toLowerCase();
        const matchesSearch = title.includes(searchTerm);
        return matchesCategory && matchesSearch;
      });

      currentPage = 1;
      render();
    }

    function render() {
      gameContainer.innerHTML = '';
      
      if (filteredGames.length === 0) {
        gameContainer.innerHTML = '<div class="no-results">No games found matching your criteria.</div>';
        paginationContainer.innerHTML = '';
        return;
      }

      const startIndex = (currentPage - 1) * gamesPerPage;
      const endIndex = startIndex + gamesPerPage;
      const gamesToShow = filteredGames.slice(startIndex, endIndex);

      gamesToShow.forEach(game => {
        gameContainer.appendChild(game.cloneNode(true));
      });
      renderPagination();
      if (currentPage > 1) {
        document.querySelector('.controls').scrollIntoView({ behavior: 'smooth', block: 'start' });
      }
    }

    function renderPagination() {
      paginationContainer.innerHTML = '';
      const totalPages = Math.ceil(filteredGames.length / gamesPerPage);
      
      if (totalPages <= 1) return;

      const maxVisibleButtons = 5;
      let startPage = Math.max(1, currentPage - Math.floor(maxVisibleButtons / 2));
      let endPage = Math.min(totalPages, startPage + maxVisibleButtons - 1);

      if (endPage - startPage + 1 < maxVisibleButtons) {
        startPage = Math.max(1, endPage - maxVisibleButtons + 1);
      }

      if (currentPage > 1) {
        const prevBtn = createPageButton('←', () => goToPage(currentPage - 1));
        paginationContainer.appendChild(prevBtn);
      }

      for (let i = startPage; i <= endPage; i++) {
        const btn = createPageButton(i, () => goToPage(i), i === currentPage);
        paginationContainer.appendChild(btn);
      }

      if (currentPage < totalPages) {
        const nextBtn = createPageButton('→', () => goToPage(currentPage + 1));
        paginationContainer.appendChild(nextBtn);
      }
    }

    function createPageButton(text, onClick, isActive = false) {
      const btn = document.createElement('button');
      btn.textContent = text;
      if (isActive) btn.classList.add('active');
      btn.onclick = onClick;
      return btn;
    }

    function goToPage(page) {
      currentPage = page;
      render();
    }

    window.onload = () => {
      applyFilters();
    };
  </script>
</div>

<footer style="margin-top: 50px; text-align: center; color: #666; font-size: 14px;">
  Generated from <a href="https://github.com/felix86-emu/compatibility-list">the felix86 compatibility list.</a>
</footer>
