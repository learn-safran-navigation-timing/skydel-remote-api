#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the antenna model for all satellites.
    ///
    /// Name              Type         Description
    /// ----------------- ------------ -----------------------------------------------------------------------------------------------------
    /// System            string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetSVAntennaModelForEachSV;
    typedef std::shared_ptr<SetSVAntennaModelForEachSV> SetSVAntennaModelForEachSVPtr;
    
    
    class SetSVAntennaModelForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSVAntennaModelForEachSV();

      SetSVAntennaModelForEachSV(const std::string& system, const std::vector<std::string>& antennaModelNames);

      static SetSVAntennaModelForEachSVPtr create(const std::string& system, const std::vector<std::string>& antennaModelNames);
      static SetSVAntennaModelForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** antennaModelNames ****
      std::vector<std::string> antennaModelNames() const;
      void setAntennaModelNames(const std::vector<std::string>& antennaModelNames);
    };
    
  }
}

