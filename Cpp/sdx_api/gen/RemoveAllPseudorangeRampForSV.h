#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove all PSR Ramps for the specified system's satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID (use 0 for all SVs).
    ///

    class RemoveAllPseudorangeRampForSV;
    typedef std::shared_ptr<RemoveAllPseudorangeRampForSV> RemoveAllPseudorangeRampForSVPtr;
    
    
    class RemoveAllPseudorangeRampForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveAllPseudorangeRampForSV();

      RemoveAllPseudorangeRampForSV(const std::string& system, int svId);

      static RemoveAllPseudorangeRampForSVPtr create(const std::string& system, int svId);
      static RemoveAllPseudorangeRampForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

