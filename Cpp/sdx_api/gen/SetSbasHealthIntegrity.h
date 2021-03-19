#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply integrity flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------
    /// Prn    int  The satellite's PRN number
    /// Health bool The integrity unhealthy flag
    ///

    class SetSbasHealthIntegrity;
    typedef std::shared_ptr<SetSbasHealthIntegrity> SetSbasHealthIntegrityPtr;
    
    
    class SetSbasHealthIntegrity : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasHealthIntegrity();

      SetSbasHealthIntegrity(int prn, bool health);
  
      static SetSbasHealthIntegrityPtr create(int prn, bool health);
      static SetSbasHealthIntegrityPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

