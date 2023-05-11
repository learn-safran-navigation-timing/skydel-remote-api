#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite pseudorange noise constant offset for all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetPseudorangeNoiseOffsetForEachSV;
    typedef std::shared_ptr<GetPseudorangeNoiseOffsetForEachSV> GetPseudorangeNoiseOffsetForEachSVPtr;
    
    
    class GetPseudorangeNoiseOffsetForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseOffsetForEachSV();

      GetPseudorangeNoiseOffsetForEachSV(const std::string& system);

      static GetPseudorangeNoiseOffsetForEachSVPtr create(const std::string& system);
      static GetPseudorangeNoiseOffsetForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

