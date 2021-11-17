#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSbasHealthService is deprecated since 21.9. You may use SetSbasSVServiceHealth.
    /// 
    /// Apply service provider for a satellite
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// Prn    int  The satellite's PRN number
    /// Health int  The service provider
    ///

    class SetSbasHealthService;
    typedef std::shared_ptr<SetSbasHealthService> SetSbasHealthServicePtr;
    
    
    class SetSbasHealthService : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasHealthService();

      SetSbasHealthService(int prn, int health);
  
      static SetSbasHealthServicePtr create(int prn, int health);
      static SetSbasHealthServicePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

