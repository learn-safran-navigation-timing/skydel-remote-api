#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import navigation message file for the specified constellation. This could be RINEX, SEM or YUMA file for GPS. Only RINEX for the others.
    ///
    /// Name         Type            Description
    /// ------------ --------------- ----------------------------------------------------------------------------------------------------------------------
    /// System       string          "GPS", "GLONASS", "Galileo", "SBAS", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// Path         string          File path
    /// Rollover     optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.
    /// DataSetName  optional string Name of the data set to import. This parameter is optional, the default value will be the name of the imported file.
    ///                              Constellations that support this parameter are  "GPS", "Galileo", "BeiDou", "QZSS" and "NavIC".
    /// NavMsgFamily optional string Navigation message family key used to specify which ephemeris navigation message type to import from a RINEX v4+ file.
    ///                              This parameter is optional and ignored for other file formats. Default values are: "GPS_LNAV" for GPS,
    ///                              "GALILEO_FNAV" for Galileo, "BEIDOU_D1_NAV" for BeiDou, "QZSS_LNAV" for QZSS and "NAVIC_NAV" for NavIC.
    ///                              Accepted values are: "GPS_LNAV", "GPS_CNAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_D2_NAV",
    ///                              "QZSS_LNAV" and "NAVIC_NAV".
    ///

    class ImportConstellationParameters;
    typedef std::shared_ptr<ImportConstellationParameters> ImportConstellationParametersPtr;
    
    
    class ImportConstellationParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportConstellationParameters();

      ImportConstellationParameters(const std::string& system, const std::string& path, const std::optional<int>& rollover = {}, const std::optional<std::string>& dataSetName = {}, const std::optional<std::string>& navMsgFamily = {});

      static ImportConstellationParametersPtr create(const std::string& system, const std::string& path, const std::optional<int>& rollover = {}, const std::optional<std::string>& dataSetName = {}, const std::optional<std::string>& navMsgFamily = {});
      static ImportConstellationParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** rollover ****
      std::optional<int> rollover() const;
      void setRollover(const std::optional<int>& rollover);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);


      // **** navMsgFamily ****
      std::optional<std::string> navMsgFamily() const;
      void setNavMsgFamily(const std::optional<std::string>& navMsgFamily);
    };
    
  }
}

