-- Create tables to store data from form.
create table `nathanlane`.`states` (
  stt_code varchar(2) not null unique primary key comment '2-CHARACTER STATE CODE'
  , stt_name varchar(50) not null comment 'STATE NAME'
) ENGINE=INNODB;

create table `nathanlane`.`people` (
  ppl_id integer not null auto_increment unique primary key comment 'SURROGATE KEY FOR PEOPLE TABLE'
  , ppl_first_name varchar(30) not null comment 'PERSON''S FIRST NAME'
  , ppl_last_name varchar(30) not null comment 'PERSON''S LAST NAME'
  , ppl_active tinyint(1) default 1 comment 'FLAG TO DEFINE WHETHER RECORD IS ACTIVE 1=TRUE, 0=FALSE'
  , ppl_address1 varchar(32) not null comment 'ADDRESS LINE ONE'
  , ppl_address2 varchar(32) not null comment 'ADDRESS LINE TWO'
  , ppl_phone varchar(10) not null comment 'PHONE NUMBER IN FORMAT AAAPPPSSSS'
  , ppl_city varchar(45) not null comment 'CITY'
  , ppl_stt_code varchar(2) not null comment '2-CHARACTER STATE CODE'
  , ppl_zip_code varchar(10) not null comment 'FIVE-DIGIT OR NINE-DIGIT ZIP CODE WITH HYPHEN'
  , ppl_date_created datetime not null comment 'DATE CONACT_INFO RECORD WAS CREATED'
  , ppl_date_updated datetime not null comment 'DATE CONACT_INFO WAS LAST UPDATED'
  , FOREIGN KEY (ppl_stt_code) REFERENCES states(stt_code) ON DELETE CASCADE
  , CONSTRAINT UNIQUE INDEX (ppl_first_name, ppl_last_name, ppl_address1, ppl_address2, ppl_city, ppl_stt_code, ppl_zip_code)
) ENGINE=INNODB;

insert into `nathanlane`.`states` (stt_name, stt_code) values ('Alabama', 'AL');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Alaska', 'AK');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Arizona', 'AZ');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Arkansas', 'AR');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('California', 'CA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Colorado', 'CO');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Connecticut', 'CT');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Delaware', 'DE');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('District of Columbia', 'DC');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Florida', 'FL');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Georgia', 'GA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Hawaii', 'HI');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Idaho', 'ID');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Illinois', 'IL');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Indiana', 'IN');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Iowa', 'IA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Kansas', 'KS');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Kentucky', 'KY');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Louisiana', 'LA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Maine', 'ME');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Maryland', 'MD');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Massachusetts', 'MA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Michigan', 'MI');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Minnesota', 'MN');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Mississippi', 'MS');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Missouri', 'MO');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Montana', 'MT');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Nebraska', 'NE');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Nevada', 'NV');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('New Hampshire', 'NH');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('New Jersey', 'NJ');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('New Mexico', 'NM');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('New York', 'NY');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('North Carolina', 'NC');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('North Dakota', 'ND');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Ohio', 'OH');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Oklahoma', 'OK');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Oregon', 'OR');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Pennsylvania', 'PA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Rhode Island', 'RI');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('South Carolina', 'SC');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('South Dakota', 'SD');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Tennessee', 'TN');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Texas', 'TX');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Utah', 'UT');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Vermont', 'VT');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Virginia', 'VA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Washington', 'WA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('West Virginia', 'WV');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Wisconsin', 'WI');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Wyoming', 'WY');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('American Samoa', 'AS');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Guam', 'GU');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Northern Mariana Islands', 'MP');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Puerto Rico', 'PR');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Virgin Islands', 'VI');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Federated States of Micronesia', 'FM');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Marshall Islands', 'MH');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Palau', 'PW');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('U.S. Armed Forces – Americas', 'AA');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('U.S. Armed Forces – Europe', 'AE');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('U.S. Armed Forces – Pacific', 'AP');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Northern Mariana Islands', 'CM');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Panama Canal Zone', 'CZ');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Nebraska', 'NB');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Philippine Islands', 'PI');
insert into `nathanlane`.`states` (stt_name, stt_code) values ('Trust Territory of the Pacific Islands', 'TT');
