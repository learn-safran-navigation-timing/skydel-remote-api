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
    /// Please note the command SetAllSatellitesPseudorangeNoiseOffset is deprecated since 21.3. You may use SetPseudorangeNoiseOffsetForEachSV.
    /// 
    /// Set the satellite pseudorange noise constant offset for all satellites.
    ///
    /// Name    Type         Description
    /// ------- ------------ ----------------------------------------------------------------
    /// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool   If true, the offset is enabled (applied)
    /// Offset  array double The constant offset in metters
    ///

    class SetAllSatellitesPseudorangeNoiseOffset;
    typedef std::shared_ptr<SetAllSatellitesPseudorangeNoiseOffset> SetAllSatellitesPseudorangeNoiseOffsetPtr;
    
    
    class SetAllSatellitesPseudorangeNoiseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetAllSatellitesPseudorangeNoiseOffset();

      SetAllSatellitesPseudorangeNoiseOffset(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);

      static SetAllSatellitesPseudorangeNoiseOffsetPtr create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);
      static SetAllSatellitesPseudorangeNoiseOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);


      // **** offset ****
      std::vector<double> offset() const;
      void setOffset(const std::vector<double>& offset);
    };
    
  }
}

