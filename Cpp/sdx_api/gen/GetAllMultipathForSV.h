#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all multipath ID for the specified satellite of the constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID
    ///

    class GetAllMultipathForSV;
    typedef std::shared_ptr<GetAllMultipathForSV> GetAllMultipathForSVPtr;
    
    
    class GetAllMultipathForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllMultipathForSV();

      GetAllMultipathForSV(const std::string& system, int svId);

      static GetAllMultipathForSVPtr create(const std::string& system, int svId);
      static GetAllMultipathForSVPtr dynamicCast(CommandBasePtr ptr);
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

