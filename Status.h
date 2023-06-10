#pragma once
// *IMPORTANT* Mold Breaker/Teravolt/Turboblaze will override all ability status immunities *IMPORTANT*
// non-volatile status (one max)
// Fire types + Water Veil/Water Bubble cannot be burned
// Steel/Poison types and Immunity mons cannot be poisoned (except by Corrosion)
// Electric types and Limber mons cannot be paralyzed
// Ice Types and Magma Armor mons cannot be frozen
// Insomnia/Vital Spirit/Sweet Veil mons cannot be slept
// Purifying Salt mons cannot be statused

enum Status {
	HEALTHY, BURN, FREEZE, PARALYSIS, POISONED, BAD_POISONED, SLEEP
};

// volatile status (gone on switch or X number of turns)
// telekinesis = all moves have 100% acc except KO moves, ground attacks will miss, grounded removes and prevents telekinesis
// grass types cannot be seeded
// ghost types cannot be trapped
// Inner Focus mons cannot be flinched, Steadfast mons get +1 speed when flinched
// Oblivious mons cannot be taunted, charmed, or intimidated
// Own Tempo mons cannot be confused or intimidated
// *EXTRA ABILITY CHANGE/REMOVE*
/* Gastro Acid fails if the target's Ability is Multitype, Stance Change, Schooling, Comatose, 
Shields Down, Disguise, RKS System, Battle Bond, Power Construct, Ice Face, Gulp Missile, As One, 
Zero to Hero, Commander, Quark Drive, or Protosynthesis.
*/

enum V_Status {
	BOUND, TRAPPED, CONFUSION, CHANGE_ABILITY, REMOVE_ABILITY, CURSE, DROWSY, EMBARGO, ENCORE, FLINCH, GROUNDED, HEAL_BLOCK, 
	IDENTIFY, NIGHTMARE, P_SONG, SEEDED, TAUNT, TELEKINESIS, TORMENT, TYPE_CHANGE
};

// battle status
// Defense Curl doubles damage of Rollout/Ice Ball
// cannot switch during recharge or rampage
enum B_Status {
	AQUA_RING, BRACING, CHARGING, CENTER_OF_ATTENTION, DEFENSE_CURL, FOCUSED, ROOTED, MAGIC_COAT, MAGNET_RISE, PROTECT, POWER_TRICK,
	RECHARGING, RAMPAGE, TAKE_AIM, TRANSFORM
};
