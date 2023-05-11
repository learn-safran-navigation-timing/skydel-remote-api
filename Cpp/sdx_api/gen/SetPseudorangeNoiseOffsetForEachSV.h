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
    /// Set the satellite pseudorange noise constant offset for all satellites.
    ///
    /// Name    Type         Description
    /// ------- ------------ ----------------------------------------------------------------
    /// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool   If true, the offset is enabled (applied)
    /// Offset  array double The constant offset in metters
    ///

    class SetPseudorangeNoiseOffsetForEachSV;
    typedef std::shared_ptr<SetPseudorangeNoiseOffsetForEachSV> SetPseudorangeNoiseOffsetForEachSVPtr;
    
    
    class SetPseudorangeNoiseOffsetForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPseudorangeNoiseOffsetForEachSV();

      SetPseudorangeNoiseOffsetForEachSV(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);

      static SetPseudorangeNoiseOffsetForEachSVPtr create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);
      static SetPseudorangeNoiseOffsetForEachSVPtr dynamicCast(CommandBasePtr ptr);
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

