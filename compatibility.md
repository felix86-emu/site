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
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/5e9ce2e4-4e26-41e2-a01c-945683843c80" alt="Unreal Tournament 99" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/128">Unreal Tournament 99</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/df20202c-e915-4fc7-b36f-bf013e004bff" alt="Insane 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/127">Insane 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/45c650d8-9072-44eb-9000-aa8a53b607fa" alt="Getting Over It with Bennett Foddy" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/126">Getting Over It with Bennett Foddy</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Heroic Games Launcher" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/125">Heroic Games Launcher</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/641d738f-7cb9-45ba-a094-c0cadaf00e79" alt="Genshin Impact" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/124">Genshin Impact</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="LEGO Star Wars III: The Clone Wars" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/123">LEGO Star Wars III: The Clone Wars</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="LEGO Indiana Jones: The Original Adventures" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/122">LEGO Indiana Jones: The Original Adventures</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/f9e06b12-8347-4067-be6c-78374b3b01a3" alt="Deponia 3: Goodbye Deponia" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/121">Deponia 3: Goodbye Deponia</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/502eb2e2-f860-45f4-a212-d6f7ba512a4e" alt="Deponia 2: Chaos on Deponia" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/120">Deponia 2: Chaos on Deponia</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="HuniePop" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/119">HuniePop</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Divinity: Original Sin - Enhanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/118">Divinity: Original Sin - Enhanced Edition</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b68cdf70-503c-4468-bfa3-fb99d966b4b2" alt="Firewatch" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/117">Firewatch</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/9dc69a65-4c6c-438a-9582-77585823c025" alt="Northgard" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/116">Northgard</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/dfafcfc6-ff57-4cbd-a6ed-5998e35460c9" alt="Overcooked! 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/115">Overcooked! 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/7c5e2a41-9209-4fd3-bd2f-b57ed577b31b" alt="Sonic Mania" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/114">Sonic Mania</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Shadowrun Returns" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/113">Shadowrun Returns</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b53c5c90-251b-42d6-bfd8-58dc4b69990f" alt="To The Moon" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/112">To The Moon</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/56ec6732-bcb3-40a7-aae3-678c0980bc89" alt="Torchlight II" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/111">Torchlight II</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="RimWorld" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/110">RimWorld</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="EVERSPACE" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/109">EVERSPACE</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/cc5d488c-6a07-4cf7-9049-d0a30b2748fb" alt="Crypt of the Necrodancer" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/108">Crypt of the Necrodancer</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/333f5ee7-99ea-402c-89c1-0e9e4b027ab0" alt="Deponia" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/107">Deponia</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/d429ca49-1287-4860-9f17-d6d50b28d7d5" alt="Stellaris" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/106">Stellaris</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="BioShock" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/105">BioShock</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="PEAK" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/104">PEAK</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Garfield Kart" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/103">Garfield Kart</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Batman: Arkham Origins" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/102">Batman: Arkham Origins</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/e2c80afe-2a82-47f9-8598-d308e6318faf" alt="Scribblenauts Unlimited" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/101">Scribblenauts Unlimited</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Noita" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/100">Noita</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/54c3b033-1c61-4b14-83e4-cafd06237532" alt="Rayman 3: Hoodlum Havoc" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/99">Rayman 3: Hoodlum Havoc</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/ffa67afd-98f1-48c6-9698-cfbcc4f4d56f" alt="STAR WARS™: Knights of the Old Republic" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/98">STAR WARS™: Knights of the Old Republic</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/c330b5fd-2f0b-49d1-ad35-ac88c1abf659" alt="Inscryption" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/97">Inscryption</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Fallout New Vegas" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/96">Fallout New Vegas</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/8747bcb2-08fd-4e1d-b3bf-8c5b18f5e1a5" alt="Postal 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/95">Postal 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/894394b6-6b0b-4593-8d0c-b718ada7fc1c" alt="Kerbal Space Program" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/94">Kerbal Space Program</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/fe34538d-7cb4-40a5-bbd5-f6c4fadd8925" alt="Hades" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/93">Hades</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/cf72eab2-96d8-4941-921d-0cfa2aa74a5e" alt="Lethal Company" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/92">Lethal Company</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/4473ae8d-43f9-4a10-8f73-fefbe4705dd3" alt="Touhou 16 - Hidden Star in Four Seasons" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/91">Touhou 16 - Hidden Star in Four Seasons</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/6dbadc73-ae27-43c6-8d06-e5433a855aee" alt="Transport Fever" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/90">Transport Fever</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/4167a8d5-3d8d-40d0-b092-8b45bf1f3bd3" alt="Assassin's Creed" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/89">Assassin's Creed</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b25798b7-d262-423b-b65f-1a98f88d72a1" alt="DOOM 3" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/88">DOOM 3</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/ddf97435-6fce-4cb4-866f-7f35b1e1e3bf" alt="Hitman: Blood Money" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/87">Hitman: Blood Money</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/f1c6d5ef-daba-4b8d-8bd6-84e9dfcd1044" alt="Hollow Knight: Silksong" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/86">Hollow Knight: Silksong</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/56c22612-7253-4f48-b399-3d93ed5c9cf4" alt="Thief Gold" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/85">Thief Gold</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Heroes of Might and Magic 3" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/84">Heroes of Might and Magic 3</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/aaa0b06b-0cd8-4b04-a44c-24276d7671bc" alt="Sleeping Dogs: Definitive Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/83">Sleeping Dogs: Definitive Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/8ea9db53-19d5-485f-8257-1613b3c31d21" alt="Warhammer 40,000: Rites of War" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/82">Warhammer 40,000: Rites of War</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/42ceafc9-ed80-4c7a-ab0d-46715a4d25fa" alt="Super Meat Boy" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/81">Super Meat Boy</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/deea2466-0bc8-434f-a76b-40498fe74eca" alt="RollerCoaster Tycoon: Deluxe" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/80">RollerCoaster Tycoon: Deluxe</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/306649e2-9fea-4c0a-aff3-3846596c92fe" alt="Counter-Strike: Source" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/79">Counter-Strike: Source</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Far Cry 2: Fortune's Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/78">Far Cry 2: Fortune's Edition</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/c132f0c2-fe70-4ddf-88e1-4855c4433c3f" alt="Far Cry" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/77">Far Cry</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/8c52f3f4-dce0-427e-a667-46745a28aaa8" alt="Faster Than Light: Advanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/76">Faster Than Light: Advanced Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/a0d7a3bb-f593-4ca5-ae12-f99c8d96768e" alt="Mini Metro" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/75">Mini Metro</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/6b156cfa-016c-4e56-baa5-46cb459f79c3" alt="Fallout 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/74">Fallout 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/9051f0d7-eec5-4cbb-bcbf-cd17f24d523a" alt="Enter The Gungeon" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/73">Enter The Gungeon</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/957ad937-aa50-48a5-b204-c6b1c5e76c75" alt="Trackmania Nations Forever" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/72">Trackmania Nations Forever</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/105068ed-3877-4aa2-b2af-1721e721c5b6" alt="SOMA" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/71">SOMA</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/eef8c579-4a1a-488c-b275-c57602862914" alt="SteamWorld Dig 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/70">SteamWorld Dig 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/0556cd8f-d519-42d4-a73b-c0b98c313b49" alt="SteamWorld Dig" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/69">SteamWorld Dig</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b6548c60-df6a-4551-9d6e-33d8cdbb2146" alt="TUNIC" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/68">TUNIC</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/feb3d986-64e8-466b-b7ef-00742372975f" alt="MiSide (Demo)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/67">MiSide (Demo)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/5ddcfab8-bf16-40ef-820d-bf4ee61c2700" alt="Max Payne 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/66">Max Payne 2</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/f5cc7f1a-5f3c-4f09-9b1f-a21c0c5a68b6" alt="Max Payne" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/65">Max Payne</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/0e292c79-41ec-4357-bf0a-156b03476fd4" alt="FEZ" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/64">FEZ</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/8237f31e-5b68-400a-a565-d80e9c352c7e" alt="Baldur's Gate II: Enhanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/63">Baldur's Gate II: Enhanced Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/673f7068-4efb-408a-b946-b76a61ddf418" alt="Baldur's Gate: Enhanced Edition" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/62">Baldur's Gate: Enhanced Edition</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/871f7e43-0c4e-4b6d-b7f5-1b344b484be8" alt="Dwarf Fortress" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/61">Dwarf Fortress</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/bb7cc63b-58c7-4f50-95c0-db2e3df58c63" alt="SpongeBob SquarePants: Battle for Bikini Bottom - Rehydrated" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/60">SpongeBob SquarePants: Battle for Bikini Bottom - Rehydrated</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/c13821a7-4047-4101-abb8-6a9a18880761" alt="DOOM (2016)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/59">DOOM (2016)</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/92170a81-1576-4b7f-b4ee-c611920a8daa" alt="Europa Universalis IV" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/58">Europa Universalis IV</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b3005874-bd78-4166-a5f5-b79365deda8a" alt="Factorio Demo" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/57">Factorio Demo</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b79e31ac-f8c2-4bef-af3a-0ea42e596cd1" alt="Witcher 3" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/56">Witcher 3</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/9d5ec40f-75ac-483c-9892-ceab9f881096" alt="Crysis" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/55">Crysis</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/a9ad7303-3aed-43db-9e50-1a07066172d4" alt="Psychonauts 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/54">Psychonauts 2</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/dd7f4939-06f3-4368-85a1-f12105703660" alt="Witcher 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/53">Witcher 2</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Among Us" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/52">Among Us</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/342d233e-821e-4be3-afa7-b7b0a5dc7993" alt="Deltarune Demo" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/51">Deltarune Demo</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/e449e5b0-5e32-4185-8410-3b3abd388389" alt="Doki Doki Literature Club" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/50">Doki Doki Literature Club</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/f83f622e-8e94-41ee-9049-0894db0fd70c" alt="2048" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/49">2048</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/125217ea-166c-4cbc-ad9d-33a642df8d78" alt="Friday Night Funkin' (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/48">Friday Night Funkin' (Windows)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/ba440d24-435f-49f8-88d7-c3cda73f7cec" alt="Sid Meier’s Civilization VI" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/47">Sid Meier’s Civilization VI</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/a7d84731-5960-4a8f-a4e0-7d2331389c25" alt="Hollow Knight" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/46">Hollow Knight</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="A Hat In Time (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/45">A Hat In Time (Windows)</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/bc8f65bb-45ae-4cfc-bebe-7bcd4a9078dd" alt="Half-Life" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/44">Half-Life</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/78668ac1-f746-460e-ad5e-92c5ff2fdf0e" alt="Counter Strike" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/43">Counter Strike</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/accb8410-b658-43e7-b23e-29b36c5d3760" alt="LIMBO" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/42">LIMBO</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/0e61ccbf-e048-47df-a047-71011527e995" alt="Portal 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/41">Portal 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/7539329f-9acc-4fb4-a265-af1c26ee9f50" alt="Volley Pals" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/40">Volley Pals</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/0ce543b7-7395-4425-9e1c-ff7e79f1ae76" alt="Bridge Constructor Portal" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/39">Bridge Constructor Portal</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/6e08c31e-8ea9-493d-b9a2-9edc915bf496" alt="140" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/38">140</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/fcd7216f-3fb4-4d90-ae75-13dc7d44b1db" alt="Death Trash (Demo)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/37">Death Trash (Demo)</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/a444dd76-5f6b-469f-a96f-c663fa9d7b94" alt="Bzzzt (Demo)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/36">Bzzzt (Demo)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/dcf8c773-94ac-4a6a-9593-a462fe8cf465" alt="Shogun Showdown: Prologue" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/35">Shogun Showdown: Prologue</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/3f9c73b6-6d6a-4eae-b722-edde2399e2c9" alt="Stardew Valley" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/34">Stardew Valley</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/cabebbc8-e17e-4b67-abd3-4f2f05af20a2" alt="Hotline Miami" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/33">Hotline Miami</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b8bfd158-6593-496a-90fa-f0a86143ca41" alt="Psychonauts" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/32">Psychonauts</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Amnesia: The Dark Descent" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/31">Amnesia: The Dark Descent</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/e7f19b61-2d7c-49ab-b301-ba6b96df2eb0" alt="Worms W.M.D." class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/30">Worms W.M.D.</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/64a3bdcf-6e3b-446d-87e7-b4cb2d6a4a70" alt="Turok" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/29">Turok</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/54e4f6d1-46e6-413d-815c-b89970ae5654" alt="5D Chess With Multiverse Time Travel" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/28">5D Chess With Multiverse Time Travel</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/d5a56dbc-aa1a-4af6-860c-5c3a6536318b" alt="Undertale" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/27">Undertale</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/859bc9fa-0a37-4083-8e74-cb61d199e89e" alt="Portal" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/26">Portal</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/8d89370b-477f-4d1d-ab41-ab75f4562c1a" alt="Pizza Tower (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/25">Pizza Tower (Windows)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/a087025a-05a9-4a53-b924-185d62311313" alt="World of Goo 2" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/24">World of Goo 2</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/f6ce84ae-44e3-4191-9b42-4af3e07666fc" alt="Shovel Knight: Specter of Torment" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/23">Shovel Knight: Specter of Torment</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Terraria" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/22">Terraria</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/2f774381-0efc-4bbe-8374-571cf880e49e" alt="Solitaire (Windows)" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/21">Solitaire (Windows)</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/c6d4418e-20ee-491f-8262-e3c339a81d36" alt="SuperTux" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/20">SuperTux</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/66c777be-8fad-428c-b47c-fcfa20fd1f5d" alt="Absolute Drift" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/19">Absolute Drift</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="partial">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/9344500c-eaf2-494a-bc78-367d4ac078d2" alt="Rogue Legacy" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/18">Rogue Legacy</a></h3>
    <span class="status yellow">Partially Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/d5e84a9a-8616-44a1-a29e-e630ee36b314" alt="60 Seconds" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/17">60 Seconds</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/f49cdb0e-c0ab-4637-b3e9-a7cf00a31f2f" alt="Baba Is You" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/16">Baba Is You</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="not-working">
  <div class="game-image-container">
    <img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Doom 64" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/15">Doom 64</a></h3>
    <span class="status red">Not Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/e263df13-15ab-4684-9f60-73c01b2777bb" alt="Outlast" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/14">Outlast</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/76aa91d7-3ac1-4a3a-8bb3-79c301d5e790" alt="Cuphead" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/13">Cuphead</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/73df69d9-1a06-46c6-ba75-503366151830" alt="Untitled Goose Game" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/12">Untitled Goose Game</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/57ce4cc1-00d0-4a61-9b1e-6c0c4da6d965" alt="Hotline Miami 2: Wrong Number" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/11">Hotline Miami 2: Wrong Number</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/35bfab4e-3179-4c4b-9ceb-a0bcdc33aa95" alt="The Binding of Isaac: Rebirth" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/10">The Binding of Isaac: Rebirth</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/81142a3e-b930-48f4-8a39-11e582cecf82" alt="Papers, Please" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/9">Papers, Please</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/31a3549f-bc95-466d-9835-8c23edfc59f4" alt="Don't Starve" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/8">Don't Starve</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/b64a3add-9848-45b5-99c0-70c5b00d80a6" alt="Dimension Tripper Neptune: TOP NEP" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/7">Dimension Tripper Neptune: TOP NEP</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/ce5c5813-977f-4f43-a371-add71944800d" alt="World of Goo" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/6">World of Goo</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/288b24a4-fe91-4309-8bc2-fd3c8a0d0a53" alt="Celeste" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/5">Celeste</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/28f85114-5a77-4afe-99bf-64bdf2aa0d6d" alt="openarena" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/4">openarena</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/13bbd99a-3b53-46bf-84e1-c854e664f315" alt="SuperTuxKart" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/3">SuperTuxKart</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/ae9186c3-8777-40ae-b26b-3a0461ca0b47" alt="VVVVVV" class="game-image">
  </div>
  <div class="game-info">
    <h3 class="game-title"><a href="https://github.com/felix86-emu/compatibility-list/issues/2">VVVVVV</a></h3>
    <span class="status green">Working</span>
  </div>
</div>
<div class="game-card" data-category="working">
  <div class="game-image-container">
    <img loading="lazy" src="https://github.com/user-attachments/assets/47ff1b5f-4d15-45dd-8dfb-bfa512b881f7" alt="Balatro" class="game-image">
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
