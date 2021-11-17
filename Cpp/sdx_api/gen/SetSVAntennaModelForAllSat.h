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
    /// Please note the command SetSVAntennaModelForAllSat is deprecated since 21.3. You may use SetSVAntennaModelForEachSV.
    /// 
    /// Set the antenna model for all satellites.
    ///
    /// Name              Type         Description
    /// ----------------- ------------ --------------------------------------------------------------------------------------------------------------------------------------------------
    /// AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => PRN 1, index 1 => PRN 2, etc and index 0 => 120, index 1 => 121, etc for SBAS)
    /// System            string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class SetSVAntennaModelForAllSat;
    typedef std::shared_ptr<SetSVAntennaModelForAllSat> SetSVAntennaModelForAllSatPtr;
    
    
    class SetSVAntennaModelForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSVAntennaModelForAllSat();

      SetSVAntennaModelForAllSat(const std::vector<std::string>& antennaModelNames, const std::string& system);
  
      static SetSVAntennaModelForAllSatPtr create(const std::vector<std::string>& antennaModelNames, const std::string& system);
      static SetSVAntennaModelForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** antennaModelNames ****
      std::vector<std::string> antennaModelNames() const;
      void setAntennaModelNames(const std::vector<std::string>& antennaModelNames);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

