#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of all the pseudorange ramps IDs for a system's satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID.
    ///

    class GetAllPseudorangeRampForSV;
    typedef std::shared_ptr<GetAllPseudorangeRampForSV> GetAllPseudorangeRampForSVPtr;
    
    
    class GetAllPseudorangeRampForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllPseudorangeRampForSV();

      GetAllPseudorangeRampForSV(const std::string& system, int svId);

      static GetAllPseudorangeRampForSVPtr create(const std::string& system, int svId);
      static GetAllPseudorangeRampForSVPtr dynamicCast(CommandBasePtr ptr);
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

