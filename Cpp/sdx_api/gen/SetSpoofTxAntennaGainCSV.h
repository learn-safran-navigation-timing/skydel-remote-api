#pragma once

#include <memory>
#include "command_base.h"

#include "gen/AntennaPatternType.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set spoofer transmitter gain antenna pattern from a CSV file.
    ///
    /// Name     Type               Description
    /// -------- ------------------ ----------------------------------------------------------------------------------------------------------------------
    /// FilePath string             File path of the CSV (see user manual for CSV file format details). For Default and None types, leave this field empty
    /// Type     AntennaPatternType Pattern type
    /// Id       string             Transmitter unique identifier.
    ///

    class SetSpoofTxAntennaGainCSV;
    typedef std::shared_ptr<SetSpoofTxAntennaGainCSV> SetSpoofTxAntennaGainCSVPtr;
    
    
    class SetSpoofTxAntennaGainCSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxAntennaGainCSV();

      SetSpoofTxAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const std::string& id);

      static SetSpoofTxAntennaGainCSVPtr create(const std::string& filePath, const Sdx::AntennaPatternType& type, const std::string& id);
      static SetSpoofTxAntennaGainCSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** type ****
      Sdx::AntennaPatternType type() const;
      void setType(const Sdx::AntennaPatternType& type);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

