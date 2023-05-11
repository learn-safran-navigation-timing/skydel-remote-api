#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the UDREI value transmitted by SBAS for the satellite of the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------
    /// System string "GPS" or "SBAS".
    /// SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).
    ///

    class GetUdreiForSV;
    typedef std::shared_ptr<GetUdreiForSV> GetUdreiForSVPtr;
    
    
    class GetUdreiForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetUdreiForSV();

      GetUdreiForSV(const std::string& system, int svId);

      static GetUdreiForSVPtr create(const std::string& system, int svId);
      static GetUdreiForSVPtr dynamicCast(CommandBasePtr ptr);
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

