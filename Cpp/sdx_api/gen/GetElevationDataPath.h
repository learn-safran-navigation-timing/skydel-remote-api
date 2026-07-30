#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the path to the directory containing the terrain elevation data files.
    ///
    /// 
    ///

    class GetElevationDataPath;
    typedef std::shared_ptr<GetElevationDataPath> GetElevationDataPathPtr;
    
    
    class GetElevationDataPath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetElevationDataPath();

      static GetElevationDataPathPtr create();
      static GetElevationDataPathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

