CREATE TABLE location (
  location_id INTEGER PRIMARY KEY ASC,
  location_name TEXT,
  location_country_code TEXT
);

insert into location (location_id, location_name, location_country_code) values (1,	'ROSTOCK',	'DE');
insert into location (location_id, location_name, location_country_code) values (2,	'LUBECK',	'DE');
insert into location (location_id, location_name, location_country_code) values (3,	'HAMBURG',	'DE');
insert into location (location_id, location_name, location_country_code) values (4,	'BREMEN',	'DE');
insert into location (location_id, location_name, location_country_code) values (5,	'HANNOVER',	'DE');
insert into location (location_id, location_name, location_country_code) values (6,	'KASSEL',	'DE');
insert into location (location_id, location_name, location_country_code) values (7,	'DUSSELDORF',	'DE');
insert into location (location_id, location_name, location_country_code) values (8,	'KOELN',	'DE');
insert into location (location_id, location_name, location_country_code) values (9,	'BONN',	'DE');
insert into location (location_id, location_name, location_country_code) values (10,	'WIESBADEN',	'DE');
insert into location (location_id, location_name, location_country_code) values (11,	'MANNHEIM',	'DE');
insert into location (location_id, location_name, location_country_code) values (12,	'KARLSRUHE',	'DE');
insert into location (location_id, location_name, location_country_code) values (13,	'BADEN BADEN',	'DE');
insert into location (location_id, location_name, location_country_code) values (14,	'NUERNBERG',	'DE');
insert into location (location_id, location_name, location_country_code) values (15,	'DRESDEN',	'DE');
insert into location (location_id, location_name, location_country_code) values (16,	'BASEL',	'CH');
insert into location (location_id, location_name, location_country_code) values (17,	'FRANKFURT',	'DE');
insert into location (location_id, location_name, location_country_code) values (18,	'STUTTGART',	'DE');
insert into location (location_id, location_name, location_country_code) values (19,	'MUENCHEN',	'DE');
insert into location (location_id, location_name, location_country_code) values (20,	'BERLIN',	'DE');
insert into location (location_id, location_name, location_country_code) values (21,	'SANKT AUGUSTIN',	'DE');

CREATE TABLE distance (
  from_location_id INTEGER,
  to_location_id INTEGER,
  kilometers REAL,
  travel_method TEXT
);

