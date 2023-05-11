#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the UDREI value transmitted by SBAS for the satellite of the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------
    /// System string "GPS" or "SBAS".
    /// SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).
    /// Udrei  int    The UDREI value.
    ///

    class SetUdreiForSV;
    typedef std::shared_ptr<SetUdreiForSV> SetUdreiForSVPtr;
    
    
    class SetUdreiForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetUdreiForSV();

      SetUdreiForSV(const std::string& system, int svId, int udrei);

      static SetUdreiForSVPtr create(const std::string& system, int svId, int udrei);
      static SetUdreiForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** udrei ****
      int udrei() const;
      void setUdrei(int udrei);
    };
    
  }
}

