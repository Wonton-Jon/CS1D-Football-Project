#include "Database.h"
#include "Team.h"
#include "Stadium.h"
#include <QFileInfo>
#include <QSqlError>
#include <QFileDialog>


Database::Database(): QSqlDatabase(addDatabase("QSQLITE"))
{
    // Set path
    setDatabaseName(QDir::currentPath() + "/db/NFLdb.db");

    // Print error if database does not open
    if (!open())
    {
        qDebug() << "Connection to database failed";
    }
    else
    {
        qDebug() << "Connection to database succeeded";
    }
}

Team* Database::GetTeamByID(const int &teamID)
{
    query.prepare("SELECT teamID, teamName, stadiumName, seatingCap, location, "
                  "conference, division, surfaceType, roofType, dateOpened "
                  "FROM teamInfo "
                  "WHERE teamID = (:teamID)");
    query.bindValue(":teamID", teamID);

    if(query.exec())
    {
        query.next();

        Team *team = new Team;
        Stadium *stadium = new Stadium;


        team->setTeamID(query.value(T_ID).toInt());
        team->setTeamName(query.value(T_TEAM_NAME).toString());
        stadium->setStadiumName(query.value(T_STADIUM_NAME).toString());
        stadium->setSeatingCapacity(query.value(T_SEATING_CAP).toInt());
        stadium->setLocation(query.value(T_LOCATION).toString());
        team->setConference(query.value(T_CONFERENCE).toString());
        team->setDivision(query.value(T_DIVISION).toString());
        stadium->setSurfaceType(query.value(T_SURFACE_TYPE).toString());
        stadium->setRoofType(query.value(T_ROOF_TYPE).toString());
        stadium->setDateOpened(query.value(T_DATE_OPENED).toInt());

        team->setStadium(stadium);

        teamDbMap[teamID] = team;
    }
    else
    {
        qDebug() << "Error " << query.lastError().text()
                 << " while executing query " << query.executedQuery();
    }

    return teamDbMap[teamID];
}

// Uber object for use in all display sections. Will overwrite upon return to homepage
QVector<Team*> Database::GetTeams()
{
    query.prepare("SELECT teamID, teamName, stadiumName, seatingCap, location, "
                  "conference, division, surfaceType, roofType, dateOpened "
                  "FROM teamInfo ");
    if(query.exec())
    {
        while(query.next())
        {
            Team *team = new Team;
            Stadium *stadium = new Stadium;

            team->setTeamID(query.value(T_ID).toInt());
            team->setTeamName(query.value(T_TEAM_NAME).toString());
            stadium->setStadiumName(query.value(T_STADIUM_NAME).toString());
            stadium->setSeatingCapacity(query.value(T_SEATING_CAP).toInt());
            stadium->setLocation(query.value(T_LOCATION).toString());
            team->setConference(query.value(T_CONFERENCE).toString());
            team->setDivision(query.value(T_DIVISION).toString());
            stadium->setSurfaceType(query.value(T_SURFACE_TYPE).toString());
            stadium->setRoofType(query.value(T_ROOF_TYPE).toString());
            stadium->setDateOpened(query.value(T_DATE_OPENED).toInt());

            team->setStadium(stadium);

            teamDbMap[team->getTeamID()] = team;
            stadiumDbMap[team->getTeamID()] = stadium;
        }
    }
    else
    {
        qDebug() << "Error " << query.lastError().text()
                 << " while executing query " << query.executedQuery();
    }


    return teamDbMap.values().toVector();
}

Stadium* Database::getStadiumByID(int stadiumID)
{
    Stadium * stadium = nullptr;

    return stadium;
}

// For use in admin section
QVector<Souvenir*> Database::getSouvenirs()
{

}

//
Souvenir* Database::getSouvenierByID(int souvenirID)
{
    Souvenir * souvenir = nullptr;

    return souvenir;
}

// TODO
int Database::GetMilesBetweenStadiums(const QString &origin, const QString &destination)
{
    query.prepare("SELECT milesBetween FROM teamDistances "
                  "WHERE fromStadium = (:fromStadium) "
                  "and toStadium = (:toStadium)");

    query.bindValue(":fromStadium", origin);
    query.bindValue(":toStadium", destination);

    if (query.exec())
    {
        query.next();
        int milesBetween = query.value(0).toInt();
        return milesBetween;
    }
    else
    {
        qDebug() << "Error " << query.lastError().text()
                 << " while executing query " << query.executedQuery();
        return -1;
    }
}

// Add souvenir to database
void AddSouvenir(const QString &team, const QString &souvenirName, const QString &price)
{

}

// Change price of souvenir in database
void UpdateSouvenirPrice(const QString &SouvenirName, const QString teamName, const QString &price)
{

}

// Remove souvenir from database
void DeleteSouvenir(const QString &SouvenirName, const QString &teamName)
{

}

// Get Info for one team (Requirement 2)
Team* GetSingleTeam(const QString &teamName);

//// Get all teams ordered by team name (Requirement 3)
//QVector<Team*> GetTeamsOrderByName()
//{

//}

//// Get all teams and stadiums ordered by stadium name (Requirement 4)
//QVector<Team*> GetTeamsOrderByStadium()
//{

//}

//// Get all AFC Teams sorted by team name (Requirement 5)
//QVector<Team*> GetAFCTeamsOrderByTeamName()
//{

//}

//// Get all NFC teams sorted by team name (Requirement 6)
//QVector<Team*> GetNFCTeamsOrderByTeamName()
//{

//}

//// Get all NFC North teams ordered by team name (Requirement 7)
//QVector<Team*> GetNorthNFCTeamsOrderByTeamName()
//{

//}

//// Get all stadiums sorted by date opened (Requirement 8)
//QVector<Team*> GetStadiumsOrderByDateOpened()
//{

//}

//// Get all open roof stadiums (Requirement 9)
//QVector<Team*> GetOpenRoofStadiums()
//{

//}

//// Get stadiums ordered by seating capacity (Requirement 10)
//QVector<Team*> GetStadiumsOrderBySeatingCap()
//{

//}

//// Get teams ordered by conference (Requirement 11)
//QVector<Team*> GetTeamsOrderByConference()
//{

//}

//// Get teams with bermuda grass surface type (Requirement 12)
//QVector<Team*> GetBermudaGrassTeams()
//{

//}

//// Get all souvenirs for one team (Requirement 13)
//Team* GetSingleTeamSouvenirs(const QString &teamName)
//{

//}

