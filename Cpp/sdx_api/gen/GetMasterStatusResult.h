#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMasterStatus.
    ///
    /// Name           Type Description
    /// -------------- ---- -------------------------------------
    /// IsMaster       bool True if Skydel is in master mode
    /// SlaveConnected int  The number of connected slaves
    /// Port           int  The listening port, 0 if not a master
    ///

    class GetMasterStatusResult;
    typedef std::shared_ptr<GetMasterStatusResult> GetMasterStatusResultPtr;
    
    
    class GetMasterStatusResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMasterStatusResult();

      GetMasterStatusResult(bool isMaster, int slaveConnected, int port);

      GetMasterStatusResult(CommandBasePtr relatedCommand, bool isMaster, int slaveConnected, int port);

      static GetMasterStatusResultPtr create(bool isMaster, int slaveConnected, int port);

      static GetMasterStatusResultPtr create(CommandBasePtr relatedCommand, bool isMaster, int slaveConnected, int port);
      static GetMasterStatusResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** isMaster ****
      bool isMaster() const;
      void setIsMaster(bool isMaster);


      // **** slaveConnected ****
      int slaveConnected() const;
      void setSlaveConnected(int slaveConnected);


      // **** port ****
      int port() const;
      void setPort(int port);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMasterStatusResult);
  }
}

