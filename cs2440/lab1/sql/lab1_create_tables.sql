-- Create tables to store data from form.
create table `nathanlane`.`people` (
  ppl_id integer not null auto_increment unique primary key comment 'SURROGATE KEY FOR PEOPLE TABLE'
  , ppl_first_name varchar(30) not null comment 'PERSON''S FIRST NAME'
  , ppl_last_name varchar(30) not null comment 'PERSON''S LAST NAME'
  , ppl_date_created datetime not null default now() comment 'DATE PERSON RECORD WAS CREATED'
  , ppl_date_updated datetime not null default now() comment 'DATE PERSON WAS LAST UPDATED'
  , ppl_active tinyint(1) default 1 comment 'FLAG TO DEFINE WHETHER RECORD IS ACTIVE 1=TRUE, 0=FALSE'
  , PRIMARY KEY (ppl_id)
) ENGINE=INNODB;

create table `nathanlane`.`contact_info` (
  cti_id integer not null auto_increment unique primary key comment 'SURROGATE KEY FOR CONACT_INFO TABLE'
  , cti_ppl_id integer not null comment 'FOREIGN KEY TO PEOPLE TABLE'
  , cti_address1 varchar(32) not null comment 'ADDRESS LINE ONE'
  , cti_address2 varchar(32) not null comment 'ADDRESS LINE TWO'
  , cti_phone varchar(10) not null comment 'PHONE NUMBER IN FORMAT AAAPPPSSSS'
  , cti_city varchar(45) not null comment 'CITY'
  , cti_state varchar(2) not null comment '2-CHARACTER STATE CODE'
  , cti_zip_code varchar(10) not null comment 'FIVE-DIGIT OR NINE-DIGIT ZIP CODE WITH HYPHEN'
  , cti_date_created datetime not null default now() comment 'DATE CONACT_INFO RECORD WAS CREATED'
  , cti_date_updated datetime not null default now() comment 'DATE CONACT_INFO WAS LAST UPDATED'
  , cti_active tinyint(1) default 1 comment 'FLAG TO DEFINE WHETHER RECORD IS ACTIVE 1=TRUE, 0=FALSE'
  , PRIMARY KEY (cti_id)
  , FOREIGN KEY (cti_ppl_id) REFERENCES people(ppl_id) ON DELETE CASCADE
) ENGINE=INNODB;

create table `nathanlane`.`states` (
  stt_id integer not null auto_increment unique primary key comment 'SURROGATE KEY FOR STATES TABLE'
  , stt_code varchar(2) not null comment '2-CHARACTER STATE CODE'
  , stt_name varchar(50) not null comment 'STATE NAME'
) ENGINE=INNODB;

insert into `nathanlane`.`states` (stt_code, stt_name) values ('Alabama', 'AL');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Alaska', 'AK');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Arizona', 'AZ');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Arkansas', 'AR');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('California', 'CA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Colorado', 'CO');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Connecticut', 'CT');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Delaware', 'DE');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('District of Columbia', 'DC');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Florida', 'FL');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Georgia', 'GA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Hawaii', 'HI');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Idaho', 'ID');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Illinois', 'IL');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Indiana', 'IN');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Iowa', 'IA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Kansas', 'KS');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Kentucky', 'KY');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Louisiana', 'LA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Maine', 'ME');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Maryland', 'MD');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Massachusetts', 'MA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Michigan', 'MI');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Minnesota', 'MN');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Mississippi', 'MS');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Missouri', 'MO');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Montana', 'MT');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Nebraska', 'NE');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Nevada', 'NV');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('New Hampshire', 'NH');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('New Jersey', 'NJ');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('New Mexico', 'NM');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('New York', 'NY');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('North Carolina', 'NC');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('North Dakota', 'ND');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Ohio', 'OH');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Oklahoma', 'OK');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Oregon', 'OR');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Pennsylvania', 'PA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Rhode Island', 'RI');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('South Carolina', 'SC');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('South Dakota', 'SD');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Tennessee', 'TN');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Texas', 'TX');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Utah', 'UT');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Vermont', 'VT');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Virginia', 'VA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Washington', 'WA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('West Virginia', 'WV');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Wisconsin', 'WI');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Wyoming', 'WY');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('American Samoa', 'AS');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Guam', 'GU');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Northern Mariana Islands', 'MP');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Puerto Rico', 'PR');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Virgin Islands', 'VI');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Federated States of Micronesia', 'FM');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Marshall Islands', 'MH');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Palau', 'PW');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('U.S. Armed Forces – Americas', 'AA');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('U.S. Armed Forces – Europe', 'AE');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('U.S. Armed Forces – Pacific', 'AP');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Northern Mariana Islands', 'CM');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Panama Canal Zone', 'CZ');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Nebraska', 'NB');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Philippine Islands', 'PI');
insert into `nathanlane`.`states` (stt_code, stt_name) values ('Trust Territory of the Pacific Islands', 'TT');